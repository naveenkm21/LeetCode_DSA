class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, size_t maxWidth) {
    vector<string> ans;
    vector<string> row;
    size_t rowLetters = 0;

    for (const string& word : words) {

      if (rowLetters + row.size() + word.length() > maxWidth) {
        const int spaces = maxWidth - rowLetters;
        if (row.size() == 1) {
          for (int i = 0; i < spaces; ++i)
            row[0] += " ";
        } else {

          for (int i = 0; i < spaces; ++i)
            row[i % (row.size() - 1)] += " ";
        }
        ans.push_back(join(row, ""));
        row.clear();
        rowLetters = 0;
      }
      row.push_back(word);
      rowLetters += word.length();
    }
    ans.push_back(ljust(join(row, " "), maxWidth));

    return ans;
  }

 private:
  string join(const vector<string>& words, const string& s) {
    string joined;
    for (int i = 0; i < words.size(); ++i) {
      joined += words[i];
      if (i != words.size() - 1)
        joined += s;
    }
    return joined;
  }

  string ljust(string s, int width) {
    for (int i = 0; i < s.length() - width; ++i)
      s += " ";
    return s;
  }
};