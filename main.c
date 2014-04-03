#include <stdio.h>
#include <unistd.h>
#include <Python.h>

/** xxx function */
static PyObject *callback_xxx(PyObject *self, PyObject *args) {
  printf("Hello World\n");
  return PyLong_FromLong(0);
}

/** yyy method table */
static PyMethodDef yyy_Methods[] = {
  {"xxx",  callback_xxx, METH_VARARGS, "A callback."},
  {NULL, NULL, 0, NULL}  /* Sentinel */
};

/* yyy module */
PyMODINIT_FUNC
inityyy(void)
{
  PyObject *m;
  m = Py_InitModule("yyy", yyy_Methods);
  if (m == NULL)
    return;
}

int main(int argc, char *argv[]) {

  /* Setup */
  Py_NoSiteFlag = 1;
  Py_SetProgramName(argv[0]);
  Py_Initialize();

  /* Register a magical C callback */
  inityyy();

  /* Run the 'main' module */
  int rtn = Py_Main(argc, argv);
  Py_Finalize();

  return rtn;
}
