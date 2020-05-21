#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int N, Q;
    cin >> N >> Q;
    
    int m_vals[N]; // Array of multiplied staggered sums
    int m_vals_mirr[N]; // Mirror version (-1 = +1)
    int m_val_cum[N][N];
    memset(m_vals, 0, sizeof(m_vals));
    memset(m_vals_mirr, 0, sizeof(m_vals_mirr));
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j <= i; j++) {
            if ((i - j) & 1) {
                m_vals[j] += -(i - j + 1) * arr[i];
                m_vals_mirr[j] += (i - j + 1) * arr[i];
            } // Odd --> -ve mult
            else {
                m_vals[j] += (i - j + 1) * arr[i];
                m_vals_mirr[j] += -(i - j + 1) * arr[i];
            }
        }
    }

    // Print m_vals (CORRECT)
    
    long long swt = 0;
    
    char op;
    int a;
    int b;
    for (int i = 0; i < Q; i++) {
        
        cin >> op >> a >> b;
        
        if (op == 'Q') { // Query
        
            if ((b - a) & 1) {
                cout << m_vals[a - 1] << " MINUS " << m_vals[b] << endl;
                swt += m_vals[a - 1] - m_vals[b];

            }
            else {
                cout << m_vals[a - 1] << " MINUS " << m_vals_mirr[b] << endl;
                swt += m_vals[a - 1] - m_vals_mirr[b];

            }            
        } else { // Update
            
            arr[a - 1] = b;
            
        }
        
    }
    
    cout << swt << endl;
    
}

int main(void) {
    
    int cases;
    cin >> cases;
    
    for (int i = 1; i <= cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}