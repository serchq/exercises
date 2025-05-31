/*
Definition:  
We are in charge of designing a system to install packages. We are required to 
support the installation of a package and all of its dependent packages.

Here is an example of a package structure that we would need to install:

A depends on B, C  
B depends on D, E, F  
C depends on F  
F depends on G

Define what a package looks like and code a solution for how the installation flow 
should look like.

Let's assume the installation logic for a singular package will be implemented by 
the appropriate platform teams. We just need to agree on an interface.
*/

// bit manipulation
// data structure
// search functions


//////////////////
/// study case ///
//////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKAGES 100

typedef struct Package {
    char name[20];
    int dependency_count;
    struct Package* dependencies[MAX_PACKAGES];
} Package;

// PackageInstaller structure to track installed packages
typedef struct {
    Package* installed[MAX_PACKAGES];
    int installed_count;
} PackageInstaller;

// Function to check if a package is already installed
int is_installed(PackageInstaller* installer, Package* package) {
    for (int i = 0; i < installer->installed_count; i++) {
        if (strcmp(installer->installed[i]->name, package->name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to install a package and its dependencies recursively
void install_package(PackageInstaller* installer, Package* package, int visited[MAX_PACKAGES], int package_index) {
    if (is_installed(installer, package)) {
        return; // Already installed
    }

    if (visited[package_index]) {
        printf("Error: Circular dependency detected at %s\n", package->name);
        return;
    }

    visited[package_index] = 1; // Mark package as visited

    // Install dependencies first
    for (int i = 0; i < package->dependency_count; i++) {
        install_package(installer, package->dependencies[i], visited, package_index + 1);
    }

    // Install the package itself
    printf("Installing %s\n", package->name);
    installer->installed[installer->installed_count++] = package;
}

// Helper function to create a package
Package* create_package(const char* name) {
    Package* package = (Package*)malloc(sizeof(Package));
    strcpy(package->name, name);
    package->dependency_count = 0;
    return package;
}

// Helper function to add a dependency
void add_dependency(Package* package, Package* dependency) {
    package->dependencies[package->dependency_count++] = dependency;
}

// Main function
int main() {
    // Create packages
    Package* G = create_package("G");
    Package* F = create_package("F");
    Package* B = create_package("B");
    Package* C = create_package("C");
    Package* A = create_package("A");
    Package* D = create_package("D");
    Package* E = create_package("E");

    // Define dependencies
    add_dependency(F, G);
    add_dependency(B, D);
    add_dependency(B, E);
    add_dependency(B, F);
    add_dependency(C, F);
    add_dependency(A, B);
    add_dependency(A, C);

    // Initialize installer
    PackageInstaller installer = { .installed_count = 0 };
    int visited[MAX_PACKAGES] = {0};

    // Install package A and its dependencies
    install_package(&installer, A, visited, 0);

    // Free allocated memory
    free(A); free(B); free(C); free(D); free(E); free(F); free(G);

    return 0;
}