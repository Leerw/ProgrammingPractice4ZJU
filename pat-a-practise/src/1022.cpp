#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

int n, m, id;
map<string, set<int> > title_books, author_books, key_books, publisher_books, year_books;
string title, author, keyword, publisher, year;

void query(map<string, set<int> > &m, string &str) {
    if (m.find(str) != m.end()) {
        for (auto it = m[str].begin(); it != m[str].end(); ++it) {
            printf("%07d\n", *it);
        }
    } else {
        printf("Not Found\n");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &id);
        getline(cin, title);
        title_books[title].insert(id);
        getline(cin, author);
        author_books[author].insert(id);
        while (cin >> keyword) {
            key_books[keyword].insert(id);
            char c = getchar();
            if (c == '\n')
                break;
        }
        getline(cin, publisher);
        publisher_books[publisher].insert(id);
        cin >> year;
        year_books[year].insert(id);
    }
    scanf("%d", &m);
    int num;
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title_books, temp);
        else if(num == 2) query(author_books, temp);
        else if(num == 3) query(key_books, temp);
        else if(num == 4) query(publisher_books,temp);
        else if(num ==5) query(year_books, temp);
    }
    return 0;
}