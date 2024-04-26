/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    string m_Name;
    int m_Age;
    double m_Income;
    int m_Postcode;

    TreeNode* m_Left;
    TreeNode* m_Right;

public:
    TreeNode(int nodeOrderID, int nodeChronologicalID, string name, int age, double income, int postcode);

    int getNodeOrderID();
    int getNodeChronologicalID();
    string getName();
    int getAge();
    double getIncome();
    int getPostcode();

    TreeNode* getLeft();
    TreeNode* getRight();

    void setNodeOrderID(int nodeOrderID);
    void setNodeChronologicalID(int nodeChronologicalID);
    void setName(string name);
    void setAge(int age);
    void setIncome(double income);
    void setPostcode(int postcode);

    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);

    void print();
};
