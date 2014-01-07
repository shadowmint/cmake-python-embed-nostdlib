#include <stdio.h>
#include <unistd.h>
#include <Python.h>

int main(int argc, char *argv[]) {

  /* Python library path default is $HOME/lib/python2.7 */
  char buffer[1024];
  getcwd(buffer, 1023);

  /* Setup */
  Py_SetPythonHome(buffer);
  Py_SetProgramName(argv[0]);
  Py_Initialize();

  /* Run the 'main' module */
  int rtn = Py_Main(argc, argv);
  Py_Finalize();

  return rtn;
}
