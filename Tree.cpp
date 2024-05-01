/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>

using namespace std;

Tree::Tree()
{
    m_anker = nullptr;
    m_CurrentNodeChronologicalID = 0;
}

Tree::~Tree()
{
    //TODO: Delete des ganzes Baumes
}

void Tree::addNode(string name, int age, double income, int postcode)
{
    int nodeOrderID = age + income + postcode;

    TreeNode* newNode = new TreeNode(nodeOrderID, m_CurrentNodeChronologicalID, name, age, income, postcode);
    m_CurrentNodeChronologicalID++;
    //Tree ist leer
    if (m_anker == nullptr) m_anker = newNode;
    //Tree ist nicht leer
    else
    {
        TreeNode* current = m_anker;
        
        while (true)
        {
            if (newNode->getNodeOrderID() < current->getNodeOrderID())
            {
                if (current->getLeft() == nullptr)
                {
                    current->setLeft(newNode);
                    break;
                }
                else current = current->getLeft();
            }
            else
            {
                if (current->getRight() == nullptr)
                {
                    current->setRight(newNode);
                    break;
                }
                else current = current->getRight();
            }
        }      
    }
}

bool Tree::deleteNode(int nodeOrderID){
    TreeNode* current = m_anker;
    TreeNode* parent = nullptr;
    bool deleted = false;

    while (current != nullptr)
    {
        if (current->getNodeOrderID() == nodeOrderID){
            //Node hat keine Kinder
            if (current->getLeft() == nullptr && current->getRight() == nullptr){
                delete current;
                if (parent == nullptr) m_anker = nullptr;
                else if (parent->getLeft() == current) parent->setLeft(nullptr);
                else parent->setRight(nullptr);
                deleted = true;
                break;
            }
            //Node hat ein Kind
            else if(current->getLeft() == nullptr && current->getRight() != nullptr 
            || current->getRight() == nullptr && current->getLeft() != nullptr){
                //erstes element
                if (parent == nullptr){
                    if (current->getLeft() != nullptr) m_anker = current->getLeft();
                    else m_anker = current->getRight();
                }
                //mitten in der Liste
                else{
                    //ist linkes Kind
                    if (parent->getLeft() == current){
                        if (current->getLeft() != nullptr) parent->setLeft(current->getLeft());
                        else parent->setLeft(current->getRight());
                    }
                    //ist rechtes Kind
                    else{
                        if (current->getLeft() != nullptr) parent->setRight(current->getLeft());
                        else parent->setRight(current->getRight());
                    }
                }
                delete current;
                deleted = true;
                break;
            }
            //Node hat zwei Kinder
            else{
                //ermitteln das min rechter Teilbaum
                TreeNode* minNode = current->getRight();
                TreeNode* minParent = current;
                while (minNode->getLeft() != nullptr)
                {
                    minParent = minNode;
                    minNode = minNode->getLeft();
                }
                
                if(minParent->getRight() != minNode){
                    if(minNode->getRight() != nullptr){
                    minParent->setLeft(minNode->getRight());
                    }
                    else{
                        minParent->setLeft(nullptr);
                    }
                }       
                minNode->setLeft(current->getLeft());
                if(minNode != current->getRight()) minNode->setRight(current->getRight());

                if (parent == nullptr) m_anker = minNode;
                else if (parent->getLeft() == current) parent->setLeft(minNode);
                else parent->setRight(minNode);

                delete current;
                deleted = true;
                break;
            }            
        }
        //weiter nach current suchen
        else{
            if (nodeOrderID > current->getNodeOrderID()){
                parent = current;
                current = current->getRight();
            }
            else{
                parent = current;
                current = current->getLeft();
            }        
        }
    }
    
    return deleted;
}

bool Tree::searchNode(string name){
    bool result = false;
    queue<TreeNode*> q;

    if(m_anker != nullptr) q.push(m_anker);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        if (current->getName() == name){
            result = true;
            break;
        }

        if (current->getLeft() != nullptr) q.push(current->getLeft());
        if (current->getRight() != nullptr) q.push(current->getRight());
    }
    
    return result;
}

void Tree::printAll(){};
void Tree::levelOrder(){};

void Tree::printPreOrder(){};
void printInOrder(){};
void printPostOrder(){};