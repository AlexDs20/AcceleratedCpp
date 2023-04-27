# 6 Using library algorithms

## some useful stuff
- find
- find_if
- find_if_not
They all return an iterator at the position when the "thing" happens if it happens, otherwise returns the second parameters


## new concept

### static (variable definition in a function)
example:
´´´
static const std::string url_ch = "~?:@";
´´´

- storage class specifier

- Local variables that are declared to be static are preserved across invocations of the function.
- Thus, the variable is constructed and initialized only on the first call.
- Subsequent calls will use the object that the first call constructed.
- If the variable is a *const* then the value will not change.

