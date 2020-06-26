<h2>Graph Coloring</h2>

<h3>問題文</h3>
グラフの彩色問題です．頂点の個数$N$，辺の本数$M$のグラフが与えられます．頂点には$0$から$N-1$までの番号が振られています．隣接する頂点同士が異なる色になるように彩色してください．この時に必要な色の数をなるべく少なくしてください．グラフは多重辺や自己ループを持ちません，また必ずしも連結ではありません．

<h4>制約</h4>
<ul>
<li>$N=100$</li>
<li>$2N \leqq M \leqq N(N-1)/4$</li>
</ul>

<h4>入力</h4>
辺は頂点$a_{i}$と頂点$b_{i}$を繋ぐ．
<div class = "iodata">
$N \ M$<br>
$a_{0} \ b_{0}$<br>
$a_{1} \ b_{1}$<br>
$\vdots$<br>
$a_{M-1} \ b_{M-1}$<br>
</div>

<h4>出力</h4>
$N$個の頂点の色を整数で出力してください．ただし整数は$0$から$N-1$の範囲で選んでください．
<div class = "iodata">
$c_{0}$<br>
$c_{1}$<br>
$\vdots$<br>
$c_{N-1}$<br>
</div>

<h3>スコア</h3>
頂点の彩色に使った整数の種類の数がそのままスコアになります．出力が問題の制約を満たさない場合は$-1$が出力されます．

<h3>テスタ</h3>
TopCoder の Marathon Match と同じです．<code>"[command]"</code>にプログラムの実行コマンド，<code>[seed]</code>に乱数のシードを入れてください．
<div class = "iodata">
<pre>
$ java -jar Tester.jar --exec "[command]" --seed [seed]
</pre>
</div>

<h4>その他オプション</h4>
<pre>
usage: Tester.jar
 -d,--debug            write the input and output of [command] as a text file.
 -e,--exec [command]   set the execution command of the solver. (required)
 -h,--help             print this message.
 -o,--save             output the visualized result in png format.
 -s,--seed [seed]      set a random seed. (required)
 -v,--vis              visualize the result.
</pre>