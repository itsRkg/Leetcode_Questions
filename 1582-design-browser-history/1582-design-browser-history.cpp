class BrowserHistory {
private:
struct dll{
    struct dll *next;
    struct dll *prev;
    string data;
} *home, *curr;

public:
    //constructor
    BrowserHistory(string homepage) {
        home = new struct dll;
        home->next=NULL;
        home->prev=NULL;
        home->data=homepage;
        curr=home;
    }
    
    void visit(string url) {
        struct dll *page = new struct dll;
        curr->next=page;
        page->prev=curr;
        page->data=url;
        curr=curr->next;
        curr->next=NULL;
    }
    
    string back(int steps) {
        
        while(steps>0 && curr->prev!=NULL )
        {
            curr=curr->prev;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps>0 && curr->next!=NULL)
        {
            curr=curr->next;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */