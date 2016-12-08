import qbs

CppApplication {

    consoleApplication: true
    cpp.cxxLanguageVersion: "c++14"
    cpp.includePaths: ["."]

    Depends {
        name: "Qt"
        submodules: ["widgets", "websockets"]
    }

    Group {
        name: "Исходники"
        files: ["*.cpp", "*.c"]
    }
    Group {
        name: "Заголовочные"
        files: ["*.h"]
    }
    Group {
        name: "Формы"
        files: ["*.ui"]
    }
    Group {
        name: "Ресурсы"
        files: ["*.qrc"]
    }
}
