# plagiarism_detection

This project compares two text files and checks how similar they are using the **Levenshtein Distance algorithm**.

# Note
- Works best for plain text files.
- Similarity over "80%" is flagged as potential plagiarism.

# How It Works
- You enter the names of two files.
- The program reads each line from both files.
- It calculates how similar the lines are.
- Then it prints the **overall similarity percentage**.

# Features
- Detects line-by-line similarity using edit distance.
- Shows similarity in percentage.
- Warns if high similarity (possible plagiarism) is found.

# How to Run
1. Make sure both files are in the same folder as the `.cpp` file.
2. Compile the code
3. Run the program
4. Enter file names when asked (e.g., `file1.txt` and `file2.txt`).

# Example Output
Similarity: 85.71%
High similarity detected. Potential plagiarism.


