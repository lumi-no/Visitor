#include <iostream>
#include <vector>
#include <memory>


class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visit(class ElementA* element) = 0;
    virtual void visit(class ElementB* element) = 0;
};


class Element {
public:
    virtual ~Element() {}
    virtual void accept(Visitor* visitor) = 0;
};

class ElementA : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
    void operationA() {
        std::cout << "ElementA operation" << std::endl;
    }
};


class ElementB : public Element {
public:
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
    void operationB() {
        std::cout << "ElementB operation" << std::endl;
    }
};

class ConcreteVisitor : public Visitor {
public:
    void visit(ElementA* element) override {
        std::cout << "Visiting ElementA" << std::endl;
        element->operationA();
    }

    void visit(ElementB* element) override {
        std::cout << "Visiting ElementB" << std::endl;
        element->operationB();
    }
};

int main() {
    std::vector<std::unique_ptr<Element>> elements;
    elements.push_back(std::make_unique<ElementA>());
    elements.push_back(std::make_unique<ElementB>());

    ConcreteVisitor visitor;

    for (auto& element : elements) {
        element->accept(&visitor);
    }

    return 0;
}
