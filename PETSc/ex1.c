#include <petscksp.h>

static char help[] = "Solves tridiagonal linear system with KSP.\n\n";

int main( int argc, char** argv)
{
  Vec x, b, u;
  Mat A; // linear system matrix
  KSP ksp; // linear solver context
  PC pc; // preconditioner

  PetscReal norm;
  PetscInt i, its;
  PetscInt n = 10;
  PetscInt col[3];

  PetscMPIInt size;
  PetscScalar one = 1.0;
  PetscScalar value[3];
  PetscBool nonzeroguess = PETSC_FALSE;
  PetscBool changepcsize = PETSC_FALSE;

  PetscErrorCode ierr;

  ierr = PetscInitialize( &argc, &argv, (char*)0, help );
  CHKERRQ( ierr );
  
  ierr = MPI_Comm_size( PETSC_COMM_WORLD, &size );
  if( size != 1 ) {
    SETERRQ( PETSC_COMM_WORLD, 1, "Nprocs must be 1" );
  }

  //
  // Get options
  //
  ierr = PetscOptionsGetInt( NULL, NULL, "-n", &n, NULL );
  //
  ierr = PetscOptionsGetBool( NULL, NULL, "-nonzero_guess", &nonzeroguess, NULL );

  //
  // Create vectors.
  // Form 1 vector from scratch and duplicate as needed.
  //
  ierr = VecCreate( PETSC_COMM_WORLD, &x );
  ierr = PetscObjectSetName( (PetscObject)x, "Solution");
  ierr = VecSetSizes( x, PETSC_DECIDE, n );
  ierr = VecSetFromOptions( x );
  //
  ierr = VecDuplicate( x, &b );
  //
  ierr = VecDuplicate( x, &u );

  //
  // Create matrix
  //
  ierr = MatCreate( PETSC_COMM_WORLD, &A );
  ierr = MatSetSizes( A, PETSC_DECIDE, PETSC_DECIDE, n, n );
  ierr = MatSetFromOptions( A );
  ierr = MatSetUp( A );

  //
  // Assemble matrix
  //
  value[0] = -1.0;
  value[1] =  2.0;
  value[2] = -1.0;
  for( i = 1; i < n - 1; i++ ) {
    col[0] = i - 1;
    col[1] = i;
    col[2] = i + 1;
    ierr = MatSetValues( A, 1, &i, 3, col, value, INSERT_VALUES );
  }
  //
  i = n - 1;
  col[0] = n - 2;
  col[1] = n - 1;
  ierr = MatSetValues( A, 1, &i, 2, col, value, INSERT_VALUES );
  //
  i = 0;
  col[0] = 0;
  col[1] = 1;
  value[0] =  2.0;
  value[1] = -1.0;
  ierr = MatSetValues( A, 1, &i, 2, col, value, INSERT_VALUES );
  //
  ierr = MatAssemblyBegin( A, MAT_FINAL_ASSEMBLY );
  ierr = MatAssemblyEnd( A, MAT_FINAL_ASSEMBLY );

  //
  // Set exact solution and compute RHS vector
  //
  ierr = VecSet( u, one );
  ierr = MatMult( A, u, b );

  //
  // Create linear solver and various options
  //




  //printf("sizeof(PetscReal) = %ld\n", sizeof(PetscReal));
  printf("Program ended normally\n");
  return 0;
}
