#include <iostream>

using namespace std;

struct ListNode{
    int m_nValue;
    ListNode *m_pValue;
    ListNode(int val):m_nValue(val){
        m_pValue = NULL;
    }
};

struct mList{
    ListNode* head;
    ListNode* cur;
    ListNode* insertNode(ListNode * pInsert){
        if(head == NULL){
            head = pInsert;
        }else{
            cur = head;
            while(cur->m_pValue){
                cur = cur->m_pValue;
            }
            cur->m_pValue = pInsert;
        }
        return pInsert;
    }
    ~mList(){
        while(head){
            cur = head;
            head = head->m_pValue;
            delete cur;
            cur = NULL;
        }
    }
    void showList(){
        if(head == NULL){
            cout<<"List is empty!"<<endl;
            return ;
        }
        
        cout<<head->m_nValue;
        
        cur = head->m_pValue;
        while(cur){
            cout<<cur->m_nValue;
            cur = cur->m_pValue;
        }
        cout<<endl;
    }
};

// 因为有可能改变头指针，所以头指针需要设置为指向ListNode指针的指针
void DeleteNode(ListNode ** pHead, ListNode * pDelete){
    if(!pHead || !pDelete){
        return ;
    }
    
    if((*pHead)->m_pValue == NULL){
        //删除唯一节点
        *pHead = NULL;
        delete pDelete;
        pDelete = NULL;
    }else if(pDelete->m_pValue == NULL){
        ListNode *tmp = *pHead;
        while(tmp->m_pValue != pDelete){
            tmp = tmp->m_pValue;
        }
        tmp->m_pValue = NULL;
        delete pDelete;
        pDelete = NULL;
    }else{
        //要删除的节点不是尾节点，即使是头节点也对
        ListNode *pNext = pDelete->m_pValue;
        pDelete->m_nValue = pNext->m_nValue;
        pDelete->m_pValue = pNext->m_pValue;
        
        delete pNext;
        pNext = NULL;
    }
}

void test1(){
    mList *ml = new mList();
    ListNode* pTest = NULL;
    ml->insertNode(new ListNode(1));
    ml->insertNode(new ListNode(2));
    ml->insertNode(new ListNode(3));
    pTest = ml->insertNode(new ListNode(4));
    
    DeleteNode(&ml->head, pTest);
    ml->showList();
}

void test2(){
    mList *ml = new mList();
    ListNode* pTest = NULL;
    pTest = ml->insertNode(new ListNode(1));
    ml->insertNode(new ListNode(2));
    ml->insertNode(new ListNode(3));
    ml->insertNode(new ListNode(4));
    
    DeleteNode(&ml->head, pTest);
    ml->showList();
}

void test3(){
    mList *ml = new mList();
    ListNode* pTest = NULL;
    pTest = ml->insertNode(new ListNode(1));
    
    DeleteNode(&ml->head, pTest);
    ml->showList();
}

void test4(){
    mList *ml = new mList();
    ListNode* pTest = NULL;
    
    DeleteNode(&ml->head, pTest);
    ml->showList();
}

int main(){
    test1();	//删除尾节点
    test2();	//删除非尾节点
    test3();	//删除唯一节点
    test4();	//空指针
    return 0;
}