struct PSInput
{
	float4 position : SV_Position;
	float3 color : COLOR0;
};

struct PSOutput
{
	float4 color : SV_Target0; // Writes to Render target 0
};

PSOutput Main(PSInput input)
{
	PSOutput output = (PSOutput)0;
	output.color = float4(input.color, 0);
	return output;
}
