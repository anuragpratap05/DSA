vector<vector<int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    vector<string> dirs = {"U", "E", "L", "S", "D", "N", "R", "W"};
    vector<vector<bool>> vis(3, vector<bool>(3, false));
    vector<string> ans;
    cout << floodFill(0, 0, 2, 2, ans, vis, "", dir, dirs) << endl;

    for (string str : ans)
    {
        cout << str << " ";
    }