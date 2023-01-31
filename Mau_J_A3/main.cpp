#include "ACStack.h"
#include "ATStack.h"
#include "MonoStack.h"
#include "fileProcessor.h"
#include "SpeakerView.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
  MonoStack<double> mono = MonoStack<double>(argv[1],'d',50);
  mono.monotonic(argv[1]);
  // SpeakerView<string> s = SpeakerView<string>(argv[1], 'd');
  // s.outputStack(argv[1]);
}