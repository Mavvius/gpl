void displayArbre(const std::string& prefix, const BSTNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->m_val << std::endl;

        // enter the next tree level - left and right branch
        displayArbre( prefix + (isLeft ? "│   " : "\t"), node->m_left, true);
        displayArbre( prefix + (isLeft ? "│   " : "\t"), node->m_right, false);
    }
}

void displayArbre(const BSTNode* node)
{
    displayArbre("", node, false);    
}

// pass the root node of your binary tree
displayArbre(root);