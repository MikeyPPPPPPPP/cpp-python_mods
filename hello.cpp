#include </usr/local/Cellar/python@3.11/3.11.6/Frameworks/Python.framework/Versions/3.11/include/python3.11/Python.h>
#include <string>
#include <iostream>
using namespace std;


int add(int num1){
    return num1 + 1;
}

static PyObject* test(PyObject* self, PyObject* args) {
    PyObject* integer;   

    if (!PyArg_ParseTuple(args, "i", &integer)) {
		return NULL;
	}
    int temp = PyArg_ParseTuple(args, "i", &integer);

    PyObject* con = PyUnicode_FromFormat("hello %i", add(temp));
    return con;
}

static PyObject* _hello_world(PyObject* self) {
	return PyUnicode_FromString("hello world");
}

static struct PyMethodDef methods[] = {
    {"test", (PyCFunction)test, METH_VARARGS},
	{"hello_world", (PyCFunction)_hello_world, METH_NOARGS},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
	PyModuleDef_HEAD_INIT,
	"Hello world",
    "Hello world mod",
	-1,
	methods
};

PyMODINIT_FUNC PyInit_hello(void){
	return PyModule_Create(&module);
}