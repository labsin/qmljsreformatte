cmake_minimum_required(VERSION 3.1.0)

project(qmljsreformatter)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Set QMLJS to build staticly
add_definitions(-DQML_BUILD_STATIC_LIB)
add_definitions(-DCPLUSPLUS_BUILD_STATIC_LIB)
add_definitions(-DLANGUAGEUTILS_BUILD_STATIC_LIB)
add_definitions(-DQT_CREATOR)
add_definitions(-DQTC_REL_TOOLS_PATH="")

include_directories(qt-creator/src/libs)
include_directories(qt-creator/src/libs/3rdparty)

set(MAIN_SRCS
    src/main.cpp
    )

set(QMLJS_SRCS
    qt-creator/src/libs/qmljs/parser/qmldirparser.cpp
    qt-creator/src/libs/qmljs/parser/qmlerror.cpp
    qt-creator/src/libs/qmljs/parser/qmljsast.cpp
    qt-creator/src/libs/qmljs/parser/qmljsastvisitor.cpp
    qt-creator/src/libs/qmljs/parser/qmljsengine_p.cpp
    qt-creator/src/libs/qmljs/parser/qmljslexer.cpp
    qt-creator/src/libs/qmljs/parser/qmljsgrammar.cpp
    qt-creator/src/libs/qmljs/parser/qmljsparser.cpp
    qt-creator/src/libs/qmljs/persistenttrie.cpp
    qt-creator/src/libs/qmljs/qmljsbind.cpp
    qt-creator/src/libs/qmljs/qmljsbundle.cpp
    qt-creator/src/libs/qmljs/qmljscodeformatter.cpp
    qt-creator/src/libs/qmljs/qmljscontext.cpp
    qt-creator/src/libs/qmljs/qmljsdialect.cpp
    qt-creator/src/libs/qmljs/qmljsdocument.cpp
    qt-creator/src/libs/qmljs/qmljsevaluate.cpp
    qt-creator/src/libs/qmljs/qmljsfindexportedcpptypes.cpp
    qt-creator/src/libs/qmljs/qmljsimportdependencies.cpp
    qt-creator/src/libs/qmljs/qmljsinterpreter.cpp
    qt-creator/src/libs/qmljs/qmljsmodelmanagerinterface.cpp
    qt-creator/src/libs/qmljs/qmljsplugindumper.cpp
    qt-creator/src/libs/qmljs/qmljsqrcparser.cpp
    qt-creator/src/libs/qmljs/qmljsreformatter.cpp
    qt-creator/src/libs/qmljs/qmljsscanner.cpp
    qt-creator/src/libs/qmljs/qmljsscopeastpath.cpp
    qt-creator/src/libs/qmljs/qmljsscopebuilder.cpp
    qt-creator/src/libs/qmljs/qmljsscopechain.cpp
    qt-creator/src/libs/qmljs/qmljstypedescriptionreader.cpp
    qt-creator/src/libs/qmljs/qmljsutils.cpp
    qt-creator/src/libs/qmljs/qmljsvalueowner.cpp
    qt-creator/src/libs/qmljs/qmljsviewercontext.cpp
    )

set(LANGUAGE_UTILS_SRCS
    qt-creator/src/libs/languageutils/componentversion.cpp
    qt-creator/src/libs/languageutils/fakemetaobject.cpp
    )

set(UTILS_SRCS
    qt-creator/src/libs/utils/environment.cpp 
    qt-creator/src/libs/utils/environmentmodel.cpp 
    qt-creator/src/libs/utils/environmentdialog.cpp 
    qt-creator/src/libs/utils/qtcprocess.cpp 
    qt-creator/src/libs/utils/reloadpromptutils.cpp 
    qt-creator/src/libs/utils/shellcommand.cpp 
    qt-creator/src/libs/utils/shellcommandpage.cpp 
    qt-creator/src/libs/utils/settingsselector.cpp 
    qt-creator/src/libs/utils/stringutils.cpp 
    qt-creator/src/libs/utils/templateengine.cpp 
    qt-creator/src/libs/utils/textfieldcheckbox.cpp 
    qt-creator/src/libs/utils/textfieldcombobox.cpp 
    #qt-creator/src/libs/utils/filesearch.cpp 
    qt-creator/src/libs/utils/pathchooser.cpp 
    qt-creator/src/libs/utils/pathlisteditor.cpp 
    qt-creator/src/libs/utils/wizard.cpp 
    qt-creator/src/libs/utils/wizardpage.cpp 
    #qt-creator/src/libs/utils/filewizardpage.cpp 
    qt-creator/src/libs/utils/filesystemwatcher.cpp 
    #qt-creator/src/libs/utils/projectintropage.cpp 
    qt-creator/src/libs/utils/filenamevalidatinglineedit.cpp 
    qt-creator/src/libs/utils/codegeneration.cpp 
    #qt-creator/src/libs/utils/newclasswidget.cpp 
    qt-creator/src/libs/utils/classnamevalidatinglineedit.cpp 
    qt-creator/src/libs/utils/linecolumnlabel.cpp 
    qt-creator/src/libs/utils/fancylineedit.cpp 
    qt-creator/src/libs/utils/qtcolorbutton.cpp 
    qt-creator/src/libs/utils/savedaction.cpp 
    qt-creator/src/libs/utils/synchronousprocess.cpp 
    qt-creator/src/libs/utils/savefile.cpp 
    qt-creator/src/libs/utils/fileutils.cpp 
    qt-creator/src/libs/utils/textfileformat.cpp 
    qt-creator/src/libs/utils/consoleprocess.cpp 
    qt-creator/src/libs/utils/uncommentselection.cpp 
    qt-creator/src/libs/utils/parameteraction.cpp 
    qt-creator/src/libs/utils/headerviewstretcher.cpp 
    qt-creator/src/libs/utils/checkablemessagebox.cpp 
    qt-creator/src/libs/utils/styledbar.cpp 
    qt-creator/src/libs/utils/stylehelper.cpp 
    qt-creator/src/libs/utils/fancymainwindow.cpp 
    qt-creator/src/libs/utils/detailsbutton.cpp 
    #qt-creator/src/libs/utils/detailswidget.cpp 
    qt-creator/src/libs/utils/changeset.cpp 
    qt-creator/src/libs/utils/faketooltip.cpp 
    qt-creator/src/libs/utils/htmldocextractor.cpp 
    qt-creator/src/libs/utils/navigationtreeview.cpp 
    qt-creator/src/libs/utils/crumblepath.cpp 
    qt-creator/src/libs/utils/historycompleter.cpp 
    qt-creator/src/libs/utils/buildablehelperlibrary.cpp 
    qt-creator/src/libs/utils/annotateditemdelegate.cpp 
    qt-creator/src/libs/utils/fileinprojectfinder.cpp 
    qt-creator/src/libs/utils/statuslabel.cpp 
    qt-creator/src/libs/utils/outputformatter.cpp 
    qt-creator/src/libs/utils/flowlayout.cpp 
    qt-creator/src/libs/utils/networkaccessmanager.cpp 
    qt-creator/src/libs/utils/persistentsettings.cpp 
    qt-creator/src/libs/utils/completingtextedit.cpp 
    qt-creator/src/libs/utils/json.cpp 
    qt-creator/src/libs/utils/portlist.cpp 
    qt-creator/src/libs/utils/appmainwindow.cpp 
    qt-creator/src/libs/utils/sleep.cpp 
    qt-creator/src/libs/utils/basetreeview.cpp 
    qt-creator/src/libs/utils/qtcassert.cpp 
    qt-creator/src/libs/utils/elfreader.cpp 
    qt-creator/src/libs/utils/bracematcher.cpp 
    qt-creator/src/libs/utils/proxyaction.cpp 
    qt-creator/src/libs/utils/elidinglabel.cpp 
    qt-creator/src/libs/utils/hostosinfo.cpp 
    qt-creator/src/libs/utils/tooltip/tooltip.cpp 
    qt-creator/src/libs/utils/tooltip/tips.cpp 
    qt-creator/src/libs/utils/unixutils.cpp 
    qt-creator/src/libs/utils/ansiescapecodehandler.cpp 
    qt-creator/src/libs/utils/execmenu.cpp 
    qt-creator/src/libs/utils/completinglineedit.cpp 
    qt-creator/src/libs/utils/winutils.cpp 
    qt-creator/src/libs/utils/itemviews.cpp 
    qt-creator/src/libs/utils/treemodel.cpp 
    qt-creator/src/libs/utils/treeviewcombobox.cpp 
    #qt-creator/src/libs/utils/proxycredentialsdialog.cpp 
    qt-creator/src/libs/utils/macroexpander.cpp 
    qt-creator/src/libs/utils/theme/theme.cpp 
    qt-creator/src/libs/utils/progressindicator.cpp 
    qt-creator/src/libs/utils/fadingindicator.cpp 
    qt-creator/src/libs/utils/overridecursor.cpp 
    qt-creator/src/libs/utils/categorysortfiltermodel.cpp 
    qt-creator/src/libs/utils/dropsupport.cpp 
    qt-creator/src/libs/utils/icon.cpp 
    qt-creator/src/libs/utils/port.cpp 
    qt-creator/src/libs/utils/runextensions.cpp
    )
if(WIN32)
    set(UTILS_SRCS
        ${UTILS_SRCS}
        qt-creator/src/libs/utils/consoleprocess_win.cpp
        )
else(WIN32)
    set(UTILS_SRCS
        ${UTILS_SRCS}
        qt-creator/src/libs/utils/consoleprocess_unix.cpp
        )
endif(WIN32)


set(CPLUSPLUS_SRCS
    qt-creator/src/libs/cplusplus/SimpleLexer.cpp 
    qt-creator/src/libs/cplusplus/CppDocument.cpp 
    qt-creator/src/libs/cplusplus/CppRewriter.cpp 
    qt-creator/src/libs/cplusplus/Overview.cpp 
    qt-creator/src/libs/cplusplus/NamePrettyPrinter.cpp 
    qt-creator/src/libs/cplusplus/TypeOfExpression.cpp 
    qt-creator/src/libs/cplusplus/TypePrettyPrinter.cpp 
    qt-creator/src/libs/cplusplus/ResolveExpression.cpp 
    qt-creator/src/libs/cplusplus/LookupItem.cpp 
    qt-creator/src/libs/cplusplus/LookupContext.cpp 
    qt-creator/src/libs/cplusplus/ASTParent.cpp 
    qt-creator/src/libs/cplusplus/ASTPath.cpp 
    qt-creator/src/libs/cplusplus/SnapshotSymbolVisitor.cpp 
    qt-creator/src/libs/cplusplus/SymbolNameVisitor.cpp 
    qt-creator/src/libs/cplusplus/DeprecatedGenTemplateInstance.cpp 
    qt-creator/src/libs/cplusplus/FindUsages.cpp 
    qt-creator/src/libs/cplusplus/DependencyTable.cpp 
    qt-creator/src/libs/cplusplus/PreprocessorClient.cpp 
    qt-creator/src/libs/cplusplus/PreprocessorEnvironment.cpp 
    qt-creator/src/libs/cplusplus/FastPreprocessor.cpp 
    qt-creator/src/libs/cplusplus/Macro.cpp 
    qt-creator/src/libs/cplusplus/pp-engine.cpp 
    qt-creator/src/libs/cplusplus/pp-scanner.cpp 
    qt-creator/src/libs/cplusplus/findcdbbreakpoint.cpp 
    qt-creator/src/libs/cplusplus/PPToken.cpp 
    qt-creator/src/libs/cplusplus/cppmodelmanagerbase.cpp
    )

set(CPLUSPLUS_3THPARTY_SRCS
    qt-creator/src/libs/3rdparty/cplusplus/AST.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ASTVisit.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ASTMatch0.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ASTVisitor.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ASTClone.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ASTPatternBuilder.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ASTMatcher.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Matcher.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Control.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/CoreTypes.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/DiagnosticClient.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/FullySpecifiedType.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Keywords.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ObjectiveCAtKeywords.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/ObjectiveCTypeQualifiers.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Lexer.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Literals.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/MemoryPool.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Name.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/NameVisitor.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Names.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Parser.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Scope.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Bind.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Symbol.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Symbols.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Token.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/TranslationUnit.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Type.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/TypeVisitor.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/QtContextKeywords.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/Templates.cpp 
    qt-creator/src/libs/3rdparty/cplusplus/SafeMatcher.cpp
    )
    
# Find the QtCore library
find_package(Qt5Core)
find_package(Qt5Quick)
find_package(Qt5Xml)
find_package(Qt5Widgets)

# Tell CMake to create the helloworld executable
add_executable(qmljsreformatter ${MAIN_SRCS} ${QMLJS_SRCS} ${LANGUAGE_UTILS_SRCS} ${UTILS_SRCS} ${CPLUSPLUS_SRCS} ${CPLUSPLUS_3THPARTY_SRCS})

# Use the Widgets module from Qt 5.
target_link_libraries(qmljsreformatter Qt5::Core Qt5::Quick Qt5::Xml Qt5::Widgets)

# Add c+11
target_compile_features(qmljsreformatter PRIVATE cxx_range_for)
