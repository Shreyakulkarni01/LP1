#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    void displayFrames(const vector<int> &frames, bool isHit, int page)
    {
        if (isHit)
        {
            cout << "Page hit: " << page << " - frame: ";
        }
        else
        {
            cout << "Page miss: " << page << " - frame: ";
        }
        for (int f : frames)
        {
            cout << f << " ";
        }
        cout << endl;
    }

    // FIFO
    void FIFO(const vector<int> &pages, int capacity)
    {
        vector<int> frames;
        int pageFaults = 0, hits = 0;
        for (int page : pages)
        {
            bool isHit = (find(frames.begin(), frames.end(), page) != frames.end());

            if (!isHit)
            {
                if (frames.size() == capacity)
                {
                    frames.erase(frames.begin());
                }
                frames.push_back(page);
                pageFaults++;
            }
            else
            {
                hits++;
            }
            displayFrames(frames, isHit, page);
        }
        cout << "Hits : " << hits << endl;
        cout << "Page Faults : " << pageFaults << endl;
        cout << "Hit Ratio : " << static_cast<double>(hits) / pages.size() << endl;
    }

    void LRU(const vector<int>& pages,int capacity)
    {
        vector<int> frames;
        unordered_map<int,int>lru_map;
        int pageFaults = 0, hits = 0;
        int time = 0;
        for (int page : pages)
        {
            bool isHit = (find(frames.begin(), frames.end(), page) != frames.end());

            if (!isHit)
            {
                if (frames.size() == capacity)
                {
                    int lru = frames[0];

                    for(int f : frames){
                        if(lru_map[f] < lru_map[lru])
                        {
                            lru = f;
                        }
                    }
                    frames.erase(remove(frames.begin(),frames.end(),lru),frames.end());
                }
                frames.push_back(page);
                pageFaults++;
            }
            else
            {
                hits++;
            }
            displayFrames(frames, isHit, page);
        }
        cout << "Hits : " << hits << endl;
        cout << "Page Faults : " << pageFaults << endl;
        cout << "Hit Ratio : " << static_cast<double>(hits) / pages.size() << endl;
    }


int main()
{

    int capacity, choice;
    cout << "Enter no. of frames : " << endl;
    cin >> capacity;

    int n;
    cout << "Enter no. of pages : " << endl;
    cin >> n;
    vector<int> pages(n);
    cout << "Enter page References : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    do
    {
        cout << "Enter Algorithm choice : \n";
        cout << "1.FIFO" << endl;
        cout << "2.LRU" << endl;
        cout << "3.Optimal" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            FIFO(pages, capacity);
            break;
        // case 2:
        //     LRU(pages, capacity);
        //     break;
        // case 3:
        //     Optimal(pages, capacity);
        //     break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid Choice /n";
            break;
        }
    }while(choice!=5);

    return 0;
}