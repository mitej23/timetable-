//emcc --bind -o example.js example.cpp
//emsdk_env.bat
#include <emscripten/bind.h>

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
}

class MyClass {
public:
  MyClass(int start, std::string y ,int end): start(start), y(y), end(end){}


  std::string getY() const { return y; }
  void setY(std::string y_) { y = y_; }

  int getStart() const { return start; }
  void setStart(int start_) { start = start_; }

  int getEnd() const { return end; }
  void setEnd(int end_) { end = end_; }

private:
  int start;
  int end;
  std::string y;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
  class_<MyClass>("MyClass")
    .constructor<int, std::string,int>()
    //.function("incrementX", &MyClass::incrementX)
    .property("y", &MyClass::getY, &MyClass::setY)
    .property("start", &MyClass::getStart, &MyClass::setStart)
    .property("end", &MyClass::getEnd, &MyClass::setEnd)
    //.class_function("getStringFromInstance", &MyClass::getStringFromInstance)
    ;
}

