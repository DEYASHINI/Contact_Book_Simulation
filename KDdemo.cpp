#include<bits/stdc++.h>
using namespace std;


struct kdNode
{
    int point[2];//to store x and y coordinate
    long long phone;
    kdNode *left, *right;
};

kdNode* newNode(int x,int y,long long ph)
{
    kdNode* temp=new kdNode;
    temp->point[0]= x;
    temp->point[1]= y;

    temp->phone=ph;
    //cout<<temp->phone;
    temp->left=temp->right=NULL;
    return temp;
}

kdNode *insertCoord(kdNode *root,int point[],long long phone,unsigned depth)
{
    if (root == NULL)
       return newNode(point[0],point[1],phone);
     unsigned currDim=depth%2;

    if (point[currDim] < (root->point[currDim]))
        root->left=insertCoord(root->left,point,phone,depth+1);
    else
        root->right=insertCoord(root->right,point,phone,depth+1);
   return root;
}

kdNode* insert(kdNode *root, int point[],unsigned long phone)
{
    return insertCoord(root,point,phone,0);
}

// A utility method to determine if two Points are same
// in K Dimensional space
bool areSamePoints(int rootPoint[],int queryPoint[])
{
    if(rootPoint[0]==queryPoint[0] && rootPoint[1]==queryPoint[1])
        return true;
    return false;
}


bool searchRec(kdNode* root,int point[],unsigned depth)
{
    if(root==NULL)
        return false;
    if(areSamePoints(root->point,point))
        return true;
    unsigned currDim=depth%2;

    if (point[currDim] < root->point[currDim])
        return searchRec(root->left,point,depth + 1);

    return searchRec(root->right,point,depth+1);
}

int distance(int point1[],int point2[])
{

    return ((point2[0]-point1[0])*(point2[0]-point1[0]))+((point2[1]-point1[1])*(point2[1]-point1[1]));
}
bool search(kdNode* root, int point[])
{
        return searchRec(root, point, 0);
}

void nearestNeighbourSearch(kdNode *root,int sPoint[], priority_queue<vector<long long>> &mxheap,int depth,int &flag,int &ctr)
{
    if(root==NULL)
        return;
if(areSamePoints(root->point,sPoint))
  {
      flag=1;
       if(root->left!=NULL)
       {
       mxheap.push({distance(root->left->point,sPoint),root->left->point[0],root->left->point[1],root->left->phone});
       ctr++;
       }
     if(root->right!=NULL)
       {
          mxheap.push({distance(root->right->point,sPoint),root->right->point[0],root->right->point[1],root->right->phone});
          ctr++;
       }
        return;
  }
    unsigned currDim=depth%2;
    if(flag==0)
    {
      if(sPoint[currDim]<root->point[currDim])
       nearestNeighbourSearch(root->left,sPoint,mxheap,depth+1,flag,ctr);
       if(mxheap.empty())
       nearestNeighbourSearch(root->right,sPoint,mxheap,depth+1,flag,ctr);
    }

    if(flag==1)
    {

        if(ctr<3)
        {
           mxheap.push({distance(root->point,sPoint),root->point[0],root->point[1],root->phone});
           ctr++;
        }
        else
        {

            if(ctr>=3 && distance(root->point,sPoint)<mxheap.top().front())
            {
                mxheap.pop();
                mxheap.push({distance(root->point,sPoint),root->point[0],root->point[1],root->phone});
            }
        }
    }
    return;

}
/////////////////////////////////DELETION//////////////////////////////////////////////////////////////////////
kdNode *minNode(kdNode *x,kdNode *y,kdNode *z,int dim)
{
    kdNode *minKd=x;
    if(y!=NULL && y->point[dim]<minKd->point[dim])
       minKd=y;
    if(z!=NULL && z->point[dim]<minKd->point[dim])
       minKd=z;
    return minKd;
}


kdNode *findMinRec(kdNode* root,int d,unsigned depth)
{
    if(root==NULL)
        return NULL;


    unsigned cd=depth%2;

    // Compare point with root with respect to cd (Current dimension)
    if(cd==d)
    {
        if(root->left==NULL)
            return root;
        return findMinRec(root->left,d,depth+1);
    }

    // If current dimension is different then minimum can be anywhere

    return minNode(root,
               findMinRec(root->left,d,depth+1),
               findMinRec(root->right,d,depth+1),d);
}


kdNode *findMin(kdNode* root,int d)
{
    return findMinRec(root,d,0);
}




void copyPoint(int p1[],int p2[])
{
   p1[0]=p2[0];
   p1[1]=p2[1];
}


kdNode *deleteNodeRec(kdNode *root,int point[],int depth)
{
    if(root==NULL)
        return NULL;
   int cd=depth%2;

    // If the point to be deleted is present at root
    if(areSamePoints(root->point,point))
    {
        //If right child is not NULL
        if(root->right!=NULL)
        {
            // Find minimum of root's dimension in right subtree
           kdNode *min=findMin(root->right,cd);

            // Copy the minimum to root
            copyPoint(root->point,min->point);

            // Recursively delete the minimum
            root->right=deleteNodeRec(root->right,min->point,depth+1);
        }
        else if(root->left!=NULL)
        {
            kdNode *min = findMin(root->left,cd);
            copyPoint(root->point, min->point);
            root->right = deleteNodeRec(root->left, min->point, depth+1);
        }
        else
        {
            delete root;
            return NULL;
        }
        return root;
    }

    // 2) If current node doesn't contain point, search downward
    if(point[cd]<root->point[cd])
        root->left=deleteNodeRec(root->left,point,depth+1);
    else
        root->right=deleteNodeRec(root->right,point,depth+1);
    return root;
}



kdNode* deleteNode(kdNode* root,int point[])
{
    return deleteNodeRec(root,point,0);
}

//////////////////////////////////////////////////DELETION OF KD NODE////////////////////////



int main()
{
    kdNode *root=NULL;
    int points[][2] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
                       {9, 1}, {2, 7}, {10, 19}};

    int n = sizeof(points)/sizeof(points[0]);
    cout<<sizeof(long long)<<endl;
    long long phone=8918616236;
         cout<<phone;

    for (int i=0; i<n; i++)
     {

         root = insert(root, points[i],phone);
     }

    int point1[] = {9,1};
    (search(root, point1))? cout << "Found\n": cout << "Not Found\n";

    int point2[] = {12, 19};
    (search(root, point2))? cout << "Found\n": cout << "Not Found\n";
     priority_queue<vector<long long>> mxheap;


     if(search(root,point1))
     {
         int flag=0,ctr=0;
         nearestNeighbourSearch(root,point1,mxheap,0,flag,ctr);

         stack<vector<long long>> mnheap;
         while(!mxheap.empty())
         {
             mnheap.push(mxheap.top());
             mxheap.pop();
         }

    while(!mnheap.empty())
    {
        vector<long long> v=mnheap.top();
        cout<<sqrt(v[0])<<" ";
        for(int i=1;i<v.size();i++)
           cout<<v[i]<<" ";
        cout<<endl;
        mnheap.pop();
    }
     }


     //to delete a node
     int point3[]={17,15};
     root=deleteNode(root,point3);


     cout<<endl<<"AFTER DELETION OF (17,15) NEAREST POINT IS:"<<endl<<endl;
     if(search(root,point1))
     {
         int flag=0,ctr=0;
         nearestNeighbourSearch(root,point1,mxheap,0,flag,ctr);

         stack<vector<long long>> mnheap;
         while(!mxheap.empty())
         {
             mnheap.push(mxheap.top());
             mxheap.pop();
         }

    while(!mnheap.empty())
    {
        vector<long long> v=mnheap.top();
        cout<<sqrt(v[0])<<" ";
        for(int i=1;i<v.size();i++)
           cout<<v[i]<<" ";
        cout<<endl;
        mnheap.pop();
    }
     }
    return 0;
}
