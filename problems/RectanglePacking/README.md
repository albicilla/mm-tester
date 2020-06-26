<h2>Rectangle Packing</h2>

<h3>問題文</h3>
長方形の詰め込み問題です．長方形が$N$個与えらます．$i$番目の長方形の横幅は$w_{i}$，縦幅$h_{i}$はです．これらの長方形を$0 \leqq x_{i},y_{i} \leqq 1000$の箱の中にはみ出たり重ならないようにしながら，なるべく小さな領域に敷き詰めてください．長方形は回転できません．

<h4>制約</h4>
<ul>
<li>$N = 100$</li>
<li>$5 \leqq w_{i}, h_{i} \leqq 100$</li>
<li>与えられた$100$個の長方形は必ず$0 \leqq x_{i},y_{i} \leqq 1000$の箱の中に収まる</li>
</ul>

<h4>入力</h4>
<div class = "iodata">
$N$<br>
$w_{0} \ h_{0}$<br>
$w_{1} \ h_{1}$<br>
$w_{2} \ h_{2}$<br>
$\vdots$<br>
$w_{N-1} \ h_{N-1}$<br>
</div>

<h4>出力</h4>
長方形の左下の座標$(x_{i},y_{i})$を入力の順番に整数で出力してください．ただし，詰め込む箱の左下の座標を$(x,y)=(0,0)$とします．
<div class = "iodata">
$x_{0} \ y_{0}$<br>
$x_{1} \ y_{1}$<br>
$x_{2} \ y_{2}$<br>
$\vdots$<br>
$x_{N-1} \ y_{N-1}$<br>
</div>

<h3>スコア</h3>
$N$個全ての長方形を詰め込んだ時の高さをスコアとします．具体的には，全ての長方形の四隅の座標の内，最も$y$座標が大きなものがスコアになります．$0 \leqq x_{i},y_{i} \leqq 1000$から飛び出していたり，長方形同士が重なっている場合$-1$となります．

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