/*二*搜索树的实现（应该好好看看）
实际上就是在二*树的基础上增加了插入、删除、查找。

*/

#include "BaseTree.h"
template <class T>
class BSTree : public BTree<T>
{
public:
	BTNode<T>* &find(const T &data) {
		BTNode<T>** p = &root;
		current = NULL;
		while(*p) {
			if ((*p)->data == data) break;
			{
				f ((*p)->data < data) {
					current = *p;
					p = &((*p)->right);
				}
				else {
					current = *p;
					p = &((*p)->left);
				}
			}
			return *p;
		}
		bool insert(const T &data) {
			BTNode<T>* &p = find(data);
			if (p) return false;
			p = new BTNode<T>(data, NULL, NULL, current);
			return true;
		}
		bool remove(const T &data) {
			return remove(find(data));
		}
private:
		bool remove(BTNode<T>* &p) {
			if (!p) return false;
			BTNode<T>* t = p;
			if (!p->left || !p->right) {
				if (!p->left) p = p->right;
				else p = p->left;
				if (p) p->parent = current;
				delete t;
				return true;
			}
			t=p->right;
			while(t->left) t=t->left;
			p->data=t->data;
			current=t->parent;
			return remove(current->left==t?current->left:current->right);
		}
	};