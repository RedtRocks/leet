
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    char text;
    int freqn;

    node *left, *right;

    node(char a, int f)
    {
        left = right = NULL;
        this->text = a;
        this->freqn = f;
    }
};

struct Compare
{
    bool operator()(node *left, node *right)
    {
        return left->freqn > right->freqn; // Min-heap (smallest frequency at top)
    }
};

void printCodes(struct node *hi, string a)
{
    if (!hi)
    {
        return;
    }

    if (hi->text != '$')
        cout << hi->text << ": " << a << "\n";

    printCodes(hi->left, a + "0");
    printCodes(hi->right, a + "1");
}

void encode(char arr[], int freq[], int size)
{
    node *left, *right, *top;

    priority_queue<node *, vector<node *>, Compare> minHeap;

    for (int i = 0; i < size; i++)
    {
        minHeap.push(new node(arr[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new node('$', left->freqn + right->freqn);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {10, 13, 37, 22, 18};

    int size = sizeof(arr) / sizeof(arr[0]);

    encode(arr, freq, size);
}