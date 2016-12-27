/*
 * bfs.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: ran
 */
#include "Bfs.h"
Bfs::Bfs() {
}

Bfs::~Bfs() {
}

bool Bfs::visited(Node* n) {
    for(int i = 0; i < (int)vis.size(); i++) {
        if (n->equal(vis.at((unsigned long)i))) {
            return true;
        }
    }
    return false;
}
Node* Bfs::path(Node* r, Node* s) {
    Node* end;
    Node* ptr;
    vector<Node*>* p;
    vis.clear();
    r->setHeight(0);
    p = r->sons();
    end = r;
    if (! r->equal(s)) {
        vis.push_back(r);
        for(int i = 0; i < r->numOfSons(); i++) {
            if (p->at((unsigned long)i) != 0) {
                if (!visited(p->at((unsigned long)i)) && p->at((unsigned long)i)->amIValid()) {
                    p->at((unsigned long)i)->setFather(r);
                    p->at((unsigned long)i)->setHeight(r->getHeight() + 1);
                    queue.push((Node *&&)p->at((unsigned long)i));
                    vis.push_back((Node *&&) p->at((unsigned long)i));
                    if (p->at((unsigned long)i)->equal(s)) {
                        end = p->at((unsigned long)i);
                        while(!queue.empty()) {
                            queue.pop();
                        }
                        break;
                    }
                }
            }
        }
        while (!queue.empty()) {
            ptr = queue.front();
            queue.pop();
            p = ptr->sons();
            for (int i = 0;i < ptr->numOfSons(); i++) {
                if (p->at((unsigned long)i) != 0) {
                    if (!visited(p->at((unsigned long)i)) && p->at((unsigned long)i)->amIValid()) {
                        p->at((unsigned long)i)->setFather(ptr);
                        p->at((unsigned long)i)->setHeight(ptr->getHeight() + 1);
                        queue.push((Node *&&)p->at((unsigned long)i));
                        vis.push_back((Node *&&)p->at((unsigned long)i));
                        if (p->at((unsigned long)i)->equal(s)) {
                            end = p->at((unsigned long)i);
                            while(!queue.empty()) {
                                queue.pop();
                            }
                            break;
                        }
                    }
                }
            }

        }
    }
    vis.clear();
    Node *ptro = end;
    while(!ptro->equal(r)) {
        ptr = ptro->getFather();
        ptr->setNext(ptro);
        ptro = ptr;
    }
    return end;
}