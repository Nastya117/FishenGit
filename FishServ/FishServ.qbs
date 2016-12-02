import qbs

CppApplication {
    consoleApplication: true
    cpp.cxxLanguageVersion: "c++14"

    Depends {
        name: "Qt"
        submodules: ["gui", "websockets"]
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
