#include "HuffmanNode.h"

HuffmanNode::HuffmanNode()
{
    m_str = "";
    m_frequency = 0;
    m_left = NULL;
    m_right = NULL;
}

HuffmanNode::HuffmanNode(char str, int frequency)
{
    m_str = str;
    m_frequency = frequency;
    m_left = NULL;
    m_right = NULL;
}

HuffmanNode::~HuffmanNode()
{
    if(m_left)
        delete m_left;
    if(m_right)
        delete m_right;
}



bool CompareNode::operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
{
    return n1->m_frequency > n2->m_frequency;
}
