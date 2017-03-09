#include <Python.h>

// Exported function
PyObject *wrap_fact(PyObject *self, PyObject *args)
{
    int n, result;

    // PyArg_ParseTuple() : parse python args to c
    // deal with non-basic types (in C) of args, try PyTuple_GetItem()
    if (!PyArg_ParseTuple(args, "i:fact", &n))
    {
        return NULL;
    }

    // get result from the function in example.c
    result = fact(n);

    // Py_BuildValue() : parse c value back to python
    // deal with non-basic types (in C) of args, try PyList_SetItem()
    return Py_BuildValue("i", result);
}

// Method list
// all method in c should written here, and add an extra array like below.
static PyMethodDef exampleMethods[] = 
{
    //    field     / c type        / meaning
    // 1. ml_name   / char *        / name of the method
    // 2. ml_meth   / PyCFunction   / pointer to the C implementation
    // 3. ml_flags  / int           / flag bits indicating how the call should be constructed
    // 4. ml_doc    / char *        / points to the contents of the docstring
    {"fact", wrap_fact, METH_VARARGS, "Caculate N!"},
    {NULL, NULL, 0, NULL}
};

// Initialization function
#if PY_MAJOR_VERSION >= 3
    // This structure should named like this : <module_name>
    static struct PyModuleDef example =
    {
        PyModuleDef_HEAD_INIT,  // m_base       / Always initialize this member to PyModuleDef_HEAD_INIT
        "example",              // m_name       / module name
        "Caculate N!",          // m_doc        / docstring
        -1,                     // m_size       / size of per-interpreter state of the module, or -1 if the module keeps state in global variables
        exampleMethods,         // m_methods    / pointer of method list
        NULL,                   // m_reload 
        NULL,                   // m_traverse 
        NULL,                   // m_clear 
        NULL,                   // m_free 
    };

    // This function should named like this : PyInit_<module_name>
    PyMODINIT_FUNC PyInit_example(void)
    {
        PyObject *m;
        // PyModule_Create() is for python 3.x
        // pointer of PyModuleDef
        m = PyModule_Create(&example);
        if (m == NULL)
        {
            return;
        }
    }
#else
    // This function should named like this : init<module_name>
    PyMODINIT_FUNC initexample()
    {
        PyObject *m;
        // Py_InitModule is for python 2.x    
        // 1. module name
        // 2. pointer of method list
        m = Py_InitModule("example", exampleMethods);
        if (m == NULL)
        {
            return;
        }
    }
#endif