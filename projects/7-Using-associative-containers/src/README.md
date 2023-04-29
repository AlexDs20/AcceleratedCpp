# 7 Using associative containers

The sequential containers keep the elements in the order we set them in until we change that.

- This chapter &rarr; examples that uses *maps* for efficient look-up programs.

## Associative container
- Keeps automatically the elements of a container in order depending on the values of the elements.
- Allow to locate elements much more quickly
- Each elements have a *key* associated for quick access
    - associative array
    - most common is called a *map*

### map
- *std::map<std::string, int> var*;
- When creating a new key with *var[key]* it initializes the value depending on the type, here *int &rarr; 0*

### Pass function as argument
We can do that by specifying
- the return type
- a function name to be used
- the argument types of the function
So that:

```
void example( return_type function(function_arguments) );
```

which in practice could be something like:

```
std::map< std::string, std::vector<int> > xref(
        std::istream& in,
        std::vector<std::string> find_words(const std::string&))
```

where we pass a function called *find_words* to the function called xref.

### Set default value to function argument
We can give a default value to an argument by setting it in the function declaration e.g.

```
std::map< std::string, std::vector<int> > xref(
        std::istream& in,
        std::vector<std::string> find_words(const std::string&) = split)
```

which means that if no function is given to *xref* for *find_words* then it will use the default which is the *split* function.
