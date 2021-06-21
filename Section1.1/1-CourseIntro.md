# USA Team site
---
- [USACO](http://usaco.org)
  - [Contests](http://usaco.org/index.php?page=contests)
    - On-Line Contests
    - The Road to the IOI Team
  - [Resources](http://usaco.org/index.php?page=resources)
    - Books about **Competitive Programming**
    
    
Note: pay attention to the challenge schedule on the front page!

# International Olympiad in Informatics
---
- [IOI](https://ioinformatics.org/)
- [Wiki](https://en.wikipedia.org/wiki/International_Olympiad_in_Informatics)

# International Collegiate Programming Contest
---
- [ICPC](https://icpc.global/)

# USACO Training Gateway
---
https://train.usaco.org/
- All submission must have a comment block at top with following contents
 - LANG:
 - TASK:
- Please be noted that these 2 lines should not contain any other characters, including '*'

## Submission

- All input/output files are named exactly after TASK keyword:
 - **<task name\>.in**
 - **<task name\>.out**
- Input file will always have the last line with an '\\n' only
- Output file should also produce an '\\n' at the end as the last finishing line

### Special notes for Java programmer:
- USACO does not expect any "package" line on top of your main class. So you have to drop it.


File I/O
---

#### Java
```java
Scanner sc = new Scanner(new File("test.in"));
int x = sc.nextInt();
int y = sc.nextInt();

FileWriter fw = new FileWriter("test.out");
fw.write( (x+y) + "\n" );
fw.close();
```

#### Python
```python
with open('test.in') as fin, open('test.out', 'w') as fout:
    fout.write ('%s\n' % sum(map(int, fin.readline().split())))
```

#### C++
```cpp
ifstream fin ("test.in");
int a, b;
fin >> a >> b;

ofstream fout ("test.out");
fout << a+b << endl;
```

# Running Code Online
---
- [Replit](https://repl.it/)
- [Judge0](https://ide.judge0.com)
- [IDE1](https://ideone.com)
- [CSA Academy](https://csacademy.com/workspace/)
- [Goorm](https://ide.goorm.io/)

You can also share code with [pastebin](https://pastebin.com) or [hastebin](https://hastebin.com).

# Running Code Locally
---

- JetBrains - [IntelliJ IDEA Community](https://www.jetbrains.com/idea/)
- Eclipse Foundation - [Eclipse](https://www.eclipse.org/eclipseide/)
- King's College London - [BlueJ](https://bluej.org/)

# Other Online Judgement Machine

- [CSES](https://cses.fi/problemset/)
- [LeetCode](https://leetcode.com/problemset/all/)
- [UVa Online](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8)