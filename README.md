# build2 Package for Geometry Central

[Geometry Central](https://github.com/nmwsharp/geometry-central">Geometry) is a modern C++ library of data structures and algorithms for geometry processing, with a particular focus on surface meshes.

[![Official](https://img.shields.io/website/https/github.com/nmwsharp/geometry-central.svg?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/nmwsharp/geometry-central)
[![build2](https://img.shields.io/website/https/github.com/build2-packaging/geometry-central.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/build2-packaging/geometry-central)
[![cppget.org](https://img.shields.io/website/https/cppget.org/libgeometrycentral.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/libgeometrycentral)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/libgeometrycentral.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/libgeometrycentral)

## Usage
As Geometry Central does not provide any versioning scheme, make sure to add the alpha section of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch this package.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/alpha
    # trust: ...

If the alpha section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/geometry-central.git

Add the respective dependency in your project's `manifest` file to make the package available for import.

    depends: libgeometrycentral ^0.0.1

The library can then be imported by the following declaration in a `buildfile`.

    import geometrycentral = libgeometrycentral%lib{geometrycentral}

## Configuration
There are no configuration options available.

## Issues and Notes
- Naming Scheme:
    + Repository Name: Same as the upstream repository: `geometry-central`
    + Project Name: Same as the upstream repository and the project name given in the upstream CMake file: `geometry-central`
    + Library Name: To be consistent with programming practices, we wanted the library name to be the name of the upstream include folder. So, `geometrycentral` without a dash.
    + Package Name: According to the recommended build2 practices, the respective library package gets the prefix `lib` and its name becomes `libgeometrycentral`.
- As Geometry Central provides many include and source files, symbolic links to their folders and not the source files itself are used. Should files be added in the future to those folders, they will be automatically included in the build process. On the other hand, we now have to blacklist some files. So, check this blacklisting for future updates.
- Currently, the optional dependency on [SuiteSparse](https://people.engr.tamu.edu/davis/suitesparse.html) is not supported because it has not been provided as a build2 package, yet. We might compensate that by making it a dependency that shall be fulfilled by the system.
- A lot of warnings are triggered by the Eigen library. Maybe we should restrict the scope of warnings.
- Currently, the library cannot be compiled with Clang 16 when used with `libstdc++` from GCC and not with `libc++`. The error originates from using Eigen and has nothing to do with Geometry Central.
- The library can be compiled with Emscripten. However, some file-based tests seem to fail.
- The library can be compiled on Windows with GCC, Clang, and MSVC. However, some tests fail for MSVC-based targets.

## Contributing
Thanks in advance for your help and contribution to keep this package up-to-date.
For now, please, file an issue on [GitHub](https://github.com/build2-packaging/geometry-central/issues) for everything that is not described below.

### Recommend Updating Version
Please, file an issue on [GitHub](https://github.com/build2-packaging/geometry-central/issues) with the new recommended version.

### Update Version by Pull Request
1. Fork the repository on [GitHub](https://github.com/build2-packaging/geometry-central) and clone it to your local machine.
2. Run `git submodule init` and `git submodule update` to get the current upstream directory.
3. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged. Here, it is probably not a version but the newest commit from the master branch instead.
4. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
5. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
6. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
7. Run `bdep ci` and test for errors.
8. If everything works fine, make a pull request on GitHub and write down the `bdep ci` link to your CI tests.
9. After a successful pull request, we will run the appropriate commands to publish a new package version.

### Update Version Directly if You Have Permissions
1. Inside the `upstream` directory, checkout the new library version `X.Y.Z` by calling `git checkout vX.Y.Z` that you want to be packaged. Here, it is probably not a version but the newest commit from the master branch instead.
2. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
3. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
4. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
5. Run `bdep ci` and test for errors and warnings.
6. When successful, run `bdep release --tag --push` to push new tag version to repository.
7. Run `bdep publish` to publish the package to [cppget.org](https://cppget.org).
