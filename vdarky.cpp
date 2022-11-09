#include <variant>
#include <iostream>

struct Leaf 
{
    int value;
    Leaf(int value) : value(value) {};
};


struct Tree
{
    std::variant<Tree*, Leaf*> left;
    std::variant<Tree*, Leaf*> right;

    int value;
    Tree(int value) : value(value) {};
};

template <typename Left, typename Right>
Tree* genconc(Left* left, Right* right)
{
    auto t = new Tree(12);
    t->left = left;
    t->right = right;

    return t;
}

void display(Leaf* l)
{
    if (l != nullptr) {
        std::cout << "Leaf: " << l->value << "\n";
    }
}

void display(Tree* t)
{
    if (t != nullptr) {
        if (auto* ptree = std::get_if<Tree*>(&t->left)) {
            display(*ptree);
        } else if (auto* pleaf = std::get_if<Leaf*>(&t->left)) {
            display(*pleaf);
        }
        std::cout << "Tree: " << t->value << "\n";
        if (auto* ptree = std::get_if<Tree*>(&t->right)) {
            display(*ptree);
        } else if (auto* pleaf = std::get_if<Leaf*>(&t->right)) {
            display(*pleaf);
        }
    }
}

int main()
{
    auto l1 = new Leaf(1);
    auto l2 = new Leaf(2);
    auto t1 = genconc(l1, l2);
    auto l3 = new Leaf(3);
    auto t2 = genconc(t1, l3);
    auto t3 = genconc(t1, t2);
    display(t3);
    return 0;
}