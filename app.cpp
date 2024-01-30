using namespace emscripten;
using emscripten::val;
using emscripten::vecFromJSArray;

// Binding code
EMSCRIPTEN_BINDINGS(App)
{
    class_<canvas::App>("App")
        .constructor<std::string, int, int>()
        .function("sendMessage", &canvas::App::sendMessage, allow_raw_pointers())
        .function("handleEventBus", &canvas::App::handleEventBus, allow_raw_pointers())
        .function("loadFont", &canvas::App::loadFont, allow_raw_pointers());
}