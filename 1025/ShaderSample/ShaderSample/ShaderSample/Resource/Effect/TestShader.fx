float		g_Alpha;
sampler		g_Texture : register(s0);
sampler		g_Texture2 : register(s1);

struct VS_OUTPUT
{
	float4 Pos		: POSITION;
	float2 UV		: TEXCOORD0;
};

VS_OUTPUT VS(
	float4 Pos		: POSITION,
	float2 UV		: TEXCOORD0)
{
	VS_OUTPUT Out;

	Out.Pos = Pos;
	Out.Pos.x = (Out.Pos.x / 1024) * 2 - 1;
	Out.Pos.y = 1 - (Out.Pos.y / 768) * 2;
	Out.UV = UV;

	return Out;
}

float4 PS(VS_OUTPUT In) : COLOR0
{
	float4 Out;
	Out = 
		(tex2D(g_Texture, In.UV) * g_Alpha) +
		(tex2D(g_Texture2, In.UV) * (1.0f - g_Alpha));

	return Out;
}

float4 PS2(VS_OUTPUT In) : COLOR0
{
	float4 Out;
	Out = tex2D(g_Texture, In.UV);

	return Out;
}

technique TShader
{
	pass P0
	{
		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 PS();
	}
	pass P1
	{
		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 PS2();
	}
}
