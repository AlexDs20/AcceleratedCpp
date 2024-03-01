#include <iostream>
#include "Handle.cpp"

int main() {

    Core* c = new Core(1);
    Core* d = new Derived();
    std::cout << c->v << std::endl;
    std::cout << d->v << std::endl;
    // std::cout << d->w << std::endl;
    delete c;
    delete d;

    Handle<Core> h(new Core(1));
    std::cout << h->v << std::endl;

    Handle<Core> j(new Derived);
    std::cout << j->v << std::endl;
    // std::cout << j->w << std::endl;
}
