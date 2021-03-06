public class Checker
{
    public static final int  MOVE_LIMIT = 100000;
    public static final long PENALTY    = 100000;

    public static boolean isValid (
        final InputData id,
        final OutputData od)
        throws Exception
    {
        if (od.M > MOVE_LIMIT) {
            System.err.println(
                "The number of slides must be less than or equal to " + 
                MOVE_LIMIT + ", but your output is " + od.M + ".");
            return false;
        }

        for (int i = 0; i < od.M; i++) {
            if (od.r[i] < 0 || od.r[i] >= id.N ||
                od.c[i] < 0 || od.c[i] >= id.N) {
                System.err.println(
                    "The coordinate r = " + od.r[i] + ", c = " + od.c[i] +
                    " is out of range.");
                return false;
            }
        }

        return true;
    }

    public static long calcScore (
        final InputData id,
        final OutputData od)
        throws Exception
    {
        if (!isValid(id, od)) {
            return -1;
        }

        int[][] B = new int[id.N][id.N];
        for (int r = 0; r < id.N; r++) {
            for (int c = 0; c < id.N; c++) {
                B[r][c] = id.B[r][c];
            }
        }

        for (int i = 0; i < od.M; i++) {
            Checker.movePannel(id.N, od.r[i], od.c[i], B);
        }

        long score = od.M;
        for (int r = 0; r < id.N; r++) {
            for (int c = 0; c < id.N; c++) {
                if (B[r][c] < 0) continue;
                long nr = (B[r][c] - 1) / id.N;
                long nc = (B[r][c] - 1) % id.N;
                long diff = Math.abs(r - nr) + Math.abs(c - nc);
                score += diff * PENALTY;
            }
        }

        return score;
    }

    public static boolean movePannel (
        final int N,
        final int r,
        final int c,
        int[][] B)
        throws Exception
    {
        if (r < 0 || r >= N) return false;
        if (c < 0 || c >= N) return false;

        int bposR = -1;
        int bposC = -1;
        for (int i = 0; i < N; i++) {
            if (B[r][i] < 0) {
                bposR = r;
                bposC = i;
            }
            if (B[i][c] < 0) {
                bposR = i;
                bposC = c;
            }
        }

        if (bposR == r && bposC != c) {
            if (c < bposC) {
                for (int ct = bposC; ct > c; ct--) {
                    B[r][ct] = B[r][ct - 1];
                }
            }
            else {
                for (int ct = bposC; ct < c; ct++) {
                    B[r][ct] = B[r][ct + 1];
                }
            }
            B[r][c] = -1;
            return true;
        }
        
        if (bposR != r && bposC == c) {
            if (r < bposR) {
                for (int rt = bposR; rt > r; rt--) {
                    B[rt][c] = B[rt - 1][c];
                }
            }
            else {
                for (int rt = bposR; rt < r; rt++) {
                    B[rt][c] = B[rt + 1][c];
                }
            }
            B[r][c] = -1;
            return true;
        }

        return false;
    }
}
