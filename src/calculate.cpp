//-----------------------------------------------------------------------------
/// @file
/// The python interface to the accypyc c++ code.
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/enum.hpp>
#include <boost/python/class.hpp>
#include <sstream>

//-----------------------------------------------------------------------------
// Globals, Constants, Defines, Macros, Forward References
//-----------------------------------------------------------------------------
namespace bp = boost::python;

std::string TestBoolStr(bool fTestBool)
{
    if(fTestBool)
        return "IsTestBool";
    return "IsNotTestBool";
}

// ============================================================================
BOOST_PYTHON_MODULE(calculate)
{
    using namespace bp;

    def("TestBoolStr", &TestBoolStr);
}
