#pragma once

#if defined(PHY_DIRECTX11)
//classes
#define RendererAPI RendererDX11
//buffer
#define MeshBufferAPI MeshBufferDX11
#define DeferredBufferAPI DeferredBufferDX11
#define RenderTextureBufferAPI RenderTextureBufferDX11
#define TextTextureBufferAPI TextTextureBufferDX11
#define TextLayoutBufferAPI TextLayoutBufferDX11
#define TextFormatBufferAPI TextFormatBufferDX11
#define InstanceBufferAPI InstanceBufferDX11
#define DynamicMeshBufferAPI DynamicMeshBufferDX11

//others
#define TextureAPI TextureDX11
#define TextureArrayAPI TextureArrayDX11
#define TextureAtlasAPI TextureAtlasDX11
#define ColorVertexAPI ColorVertexDX11
#define NormalVertexAPI NormalVertexDX11
#define TextureVertexAPI TextureVertexDX11
#define InstanceDataAPI InstanceDataDX11

//forward shader
#define ShaderManagerAPI ShaderManagerDX11
#define ColorShaderAPI ColorShaderDX11
#define TextureShaderAPI TextureShaderDX11
#define InstanceTextureShaderAPI InstanceTextureShaderDX11
#define ForwardDirectionalLightShaderAPI ForwardDirectionalLightShaderDX11
#define MultiTextureShaderAPI MultiTextureShaderDX11
#define AlphaMappingShaderAPI AlphaMappingShaderDX11
#define LightMappingShaderAPI LightMappingShaderDX11
#define NormalMappingShaderAPI NormalMappingShaderDX11
#define SpecularMappingShaderAPI SpecularMappingShaderDX11


//deferred shader
#define DeferredDirectionalLightShaderAPI DeferredDirectionalLightShaderDX11
#define DeferredBufferShaderAPI DeferredBufferShaderDX11

//includes
#define IncludeRendererAPI "../API/DX11/RendererDX11.hpp"
#define IncludeMeshBufferAPI "../API/DX11/Buffer/MeshBufferDX11.hpp"
#define IncludeDeferredBufferAPI "../API/DX11/Buffer/DeferredBufferDX11.hpp"
#define IncludeRenderTextureBufferAPI "../API/DX11/Buffer/RenderTextureBufferDX11.hpp"
#define IncludeTextTextureBufferAPI "../API/DX11/Buffer/TextTextureBufferDX11.hpp"
#define IncludeTextLayoutBufferAPI "../API/DX11/Buffer/TextLayoutBufferDX11.hpp"
#define IncludeTextFormatBufferAPI "../API/DX11/Buffer/TextFormatBufferDX11.hpp"
#define IncludeInstanceBufferAPI "../API/DX11/Buffer/InstanceBufferDX11.hpp"
#define IncludeDynamicMeshBufferAPI "../API/DX11/Buffer/DynamicMeshBufferDX11.hpp"

#define IncludeTextureAPI "../API/DX11/Texture/TextureDX11.hpp"
#define IncludeTextureArrayAPI "../API/DX11/Texture/TextureArrayDX11.hpp"
#define IncludeTextureAtlasAPI "../API/DX11/Texture/TextureAtlasDX11.hpp"
#define IncludeColorVertexAPI "../API/DX11/Vertex/ColorVertexDX11.hpp"
#define IncludeNormalVertexAPI "../API/DX11/Vertex/NormalVertexDX11.hpp"
#define IncludeTextureVertexAPI "../API/DX11/Vertex/TextureVertexDX11.hpp"
#define IncludeShaderManagerAPI "../API/DX11/Shader/ShaderManagerDX11.hpp"
#define IncludeInstanceDataAPI "../API/DX11/Vertex/InstanceDataDX11.hpp"

//forward
#define IncludeColorShaderAPI "../../API/DX11/Shader/Forward/ColorShaderDX11.hpp"
#define IncludeTextureShaderAPI "../../API/DX11/Shader/Forward/TextureShaderDX11.hpp"
#define IncludeInstanceTextureShaderAPI "../../API/DX11/Shader/Forward/InstanceTextureShaderDX11.hpp"
#define IncludeForwardDirectionalLightShaderAPI "../../API/DX11/Shader/Forward/ForwardDirectionalLightShaderDX11.hpp"
#define IncludeMultiTextureShaderAPI "../../API/DX11/Shader/Forward/MultiTextureShaderDX11.hpp"
#define IncludeAlphaMappingShaderAPI "../../API/DX11/Shader/Forward/AlphaMappingShaderDX11.hpp"
#define IncludeLightMappingShaderAPI "../../API/DX11/Shader/Forward/LightMappingShaderDX11.hpp"
#define IncludeNormalMappingShaderAPI "../../API/DX11/Shader/Forward/NormalMappingShaderDX11.hpp"
#define IncludeSpecularMappingShaderAPI "../../API/DX11/Shader/Forward/SpecularMappingShaderDX11.hpp"

//deferred
#define IncludeDeferredBufferShaderAPI "../../API/DX11/Shader/Deferred/DeferredBufferShaderDX11.hpp"
#define IncludeDeferredDirectionalLightShaderAPI "../../API/DX11/Shader/Deferred/DeferredDirectionalLightShaderDX11.hpp"

#endif
