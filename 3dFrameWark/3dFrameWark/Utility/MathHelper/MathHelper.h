#ifndef MATH_HELPER_H_
#define MATH_HELPER_H_

// マスヘルパークラス
class MathHelper {
public:
	// πの値
	static const float Pi;
	// 値を指定された範囲内に制限
	static float Clamp(float value, float min, float max);
	// 値を指定された範囲内に制限(int)
	static int ClampInt(int value, int min, int max);
	// 2つの値の差の絶対値を計算
	static float Distance(float n1, float n2);
	// 2つの値の間を線形補間
	static float Lerp(float value1, float value2, float amount);
	// ラジアンを度に変換
	static float ToDegrees(float radians);
	// 度をラジアンに変換
	static float ToRadians(float degree);
	// サイン
	static float Sin(float degree);
	// コサイン
	static float Cos(float degree);
	// タンジェント
	static float Tan(float degree);
	// 逆サイン
	static float ASin(float s);
	// 逆コサイン
	static float ACos(float c);
	// 逆タンジェント
	static float ATan(float y, float x);
};

#endif
