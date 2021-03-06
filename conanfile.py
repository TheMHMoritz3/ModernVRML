from conans import ConanFile, CMake, tools
import os


class LibnameConan(ConanFile):
    name = "ModernVRML"
    description = "Keep it short"
    topics = ("conan", "libname", "logging")
    url = "https://github.com/themhmoritz3/conan-ModernVRML"
    homepage = "https://github.com/original_author/original_lib"
    license = "MIT"  # Indicates license type of the packaged library; please use SPDX Identifiers https://spdx.org/licenses/
    exports_sources = ["*"]
    generators = "cmake"

    version = "NVP"

    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}

    _source_subfolder = "."
    _build_subfolder = "build_subfolder"
    _cmake = None

    requires = ()

    def config_options(self):
        if self.settings.os == 'Windows':
            del self.options.fPIC

    def requirements(self):
        if self.settings.os == 'Linux':
            self.requires("boost/1.72.0")

    def source(self):
        tools.replace_in_file(self._source_subfolder+"/CMakeLists.txt", "project(ModernVRML VERSION 0.0.1 DESCRIPTION \"mylib description\")",
                              '''if(EXISTS "${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake")
  include("${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake")
else()
  include(../conanbuildinfo.cmake)
endif()
conan_basic_setup()''')
        #tools.get(**self.conan_data["sources"][self.version])
        #extracted_dir = self.name + "-" + self.version
        #os.rename(extracted_dir, self._source_subfolder)

    def _configure_cmake(self):
        if not self._cmake:
            self._cmake = CMake(self)
            self._cmake.definitions["BUILD_TESTS"] = False  # example
            self._cmake.configure(source_folder=self._source_subfolder, build_folder=self._build_subfolder)
        return self._cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        self.copy(pattern="LICENSE", dst="licenses", src=self._source_subfolder)
        cmake = self._configure_cmake()
        cmake.install()
        # If the CMakeLists.txt has a proper install method, the steps below may be redundant
        # If so, you can just remove the lines below
        include_folder = os.path.join(self._source_subfolder, "include")
        self.copy(pattern="*", dst="include", src=include_folder)
        self.copy(pattern="*.dll", dst="bin", keep_path=False)
        self.copy(pattern="*.lib", dst="lib", keep_path=False)
        self.copy(pattern="*.a", dst="lib", keep_path=False)
        self.copy(pattern="*.so*", dst="lib", keep_path=False)
        self.copy(pattern="*.dylib", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
