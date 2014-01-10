#include <stdio.h>
#include <unistd.h>
#include <Python.h>

int main(int argc, char *argv[]) {

  /* Setup */
  Py_NoSiteFlag = 1;
  Py_SetProgramName(argv[0]);
  Py_Initialize();

  /* Run the 'main' module */
  int rtn = Py_Main(argc, argv);
  Py_Finalize();

  return rtn;
}
