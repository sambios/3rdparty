#include "arcsoft_face_sdk.h"
#include "amcomdef.h"
#include "asvloffscreen.h"
#include "merror.h"
#include <iostream>  
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define APPID "�������ص�APPID"
#define SDKKey "�������ص�SDKKey"

#define NSCALE "nscaleֵ��IMAGEģʽ��2-32��videoģʽ��2-16���Ƽ�ֵ16" 
#define FACENUM	"����������"

#define SafeFree(p) { if ((p)) free(p); (p) = NULL; }
#define SafeArrayDelete(p) { if ((p)) delete [] (p); (p) = NULL; } 
#define SafeDelete(p) { if ((p)) delete (p); (p) = NULL; } 

int main()
{
	//����SDK
	MRESULT res = ASFActivation(APPID, SDKKey);
	if (MOK != res && MERR_ASF_ALREADY_ACTIVATED != res)
		printf("ALActivation fail: %d\n", res);
	else
		printf("ALActivation sucess: %d\n", res);

	//��ʼ������
	MHandle handle = NULL;
	MInt32 mask = ASF_FACE_DETECT | ASF_FACERECOGNITION | ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE;
	res = ASFInitEngine(ASF_DETECT_MODE_IMAGE, ASF_OP_0_ONLY, NSCALE, FACENUM, mask, &handle);
	if (res != MOK)
		printf("ALInitEngine fail: %d\n", res);
	else
		printf("ALInitEngine sucess: %d\n", res);
	
	char* picPath1 = "ͼƬ·��,����bgr24��ʽͼƬ";
	int Width1 = ͼƬ���;
	int Height1 = ͼƬ�߶�;
	int Format1 = ASVL_PAF_RGB24_B8G8R8;
	MUInt8* imageData1 = (MUInt8*)malloc(Height1*Width1*3);
	FILE* fp1 = fopen(picPath1, "rb");
	
	char* picPath2 = "ͼƬ·��,����bgr24��ʽͼƬ";
	int Width2 = ͼƬ���;
	int Height2 = ͼƬ�߶�;
	int Format2 = ASVL_PAF_RGB24_B8G8R8;
	MUInt8* imageData2 = (MUInt8*)malloc(Height2*Width2*3);
	FILE* fp2 = fopen(picPath2, "rb");

	if (fp1 && fp2)
	{
		fread(imageData1, 1, Height1*Width1*3, fp1);	//��ͼƬ����
		fclose(fp1);
		fread(imageData2, 1, Height2*Width2*3, fp2);	//��ͼƬ����
		fclose(fp2);
		
		// �������
		ASF_MultiFaceInfo detectedFaces1 = { 0 };
		ASF_SingleFaceInfo SingleDetectedFaces = { 0 };
		ASF_FaceFeature feature1 = { 0 };
		ASF_FaceFeature copyfeature1 = { 0 };
		res = ASFDetectFaces(handle, Width1, Height1, ASVL_PAF_RGB24_B8G8R8, imageData1, &detectedFaces1);
		if (res != MOK)
			printf("%s ASFDetectFaces fail: %d\n", picPath1, res);
		else
		{
			printf("%s ASFDetectFaces sucess: %d\n", picPath1, res);
			SingleDetectedFaces.faceRect.left = detectedFaces1.faceRect[0].left;
			SingleDetectedFaces.faceRect.top = detectedFaces1.faceRect[0].top;
			SingleDetectedFaces.faceRect.right = detectedFaces1.faceRect[0].right;
			SingleDetectedFaces.faceRect.bottom = detectedFaces1.faceRect[0].bottom;
			SingleDetectedFaces.faceOrient = detectedFaces1.faceOrient[0];
		}
		
		// ������������ȡ
		res = ASFFaceFeatureExtract(handle, Width1, Height1, ASVL_PAF_RGB24_B8G8R8, imageData1, &SingleDetectedFaces, &feature1);
		if (res != MOK)
			printf("%s ASFFaceFeatureExtract fail: %d\n", picPath1, res);
		else
		{
			printf("%s ASFFaceFeatureExtract 1 sucess: %d\n", picPath1, res);
			//����feature������ڶ��ν���������ȡ���Ḳ�ǵ�һ��������ȡ�����ݣ����±ȶԵĽ��Ϊ1
			copyfeature1.featureSize = feature1.featureSize;
			copyfeature1.feature = (MByte *)malloc(feature1.featureSize);
			memset(copyfeature1.feature, 0, feature1.featureSize);
			memcpy(copyfeature1.feature, feature1.feature, feature1.featureSize);
		}
		
		ASF_MultiFaceInfo detectedFaces2 = { 0 };
		ASF_FaceFeature feature2 = { 0 };
		res = ASFDetectFaces(handle, Width2, Height2, ASVL_PAF_RGB24_B8G8R8, imageData2, &detectedFaces2);
		if (res != MOK)
			printf("%s ASFDetectFaces fail: %d\n", picPath2, res);
		else
		{
			printf("%s ASFDetectFaces sucess: %d\n", picPath2, res);
			SingleDetectedFaces.faceRect.left = detectedFaces2.faceRect[0].left;
			SingleDetectedFaces.faceRect.top = detectedFaces2.faceRect[0].top;
			SingleDetectedFaces.faceRect.right = detectedFaces2.faceRect[0].right;
			SingleDetectedFaces.faceRect.bottom = detectedFaces2.faceRect[0].bottom;
			SingleDetectedFaces.faceOrient = detectedFaces2.faceOrient[0];
		}

		res = ASFFaceFeatureExtract(handle, Width2, Height2, ASVL_PAF_RGB24_B8G8R8, imageData2, &SingleDetectedFaces, &feature2);
		if (res != MOK)
			printf("%s ASFFaceFeatureExtract fail: %d\n", picPath2, res);
		else
			printf("%s ASFFaceFeatureExtract sucess: %d\n", picPath2, res);

		// �����������ȶ�
		MFloat confidenceLevel;
		res = ASFFaceFeatureCompare(handle, &copyfeature1, &feature2, &confidenceLevel);
		if (res != MOK)
			printf("ASFFaceFeatureCompare fail: %d\n", res);
		else
			printf("ASFFaceFeatureCompare sucess: %lf\n", confidenceLevel);

		// ������Ϣ���
		MInt32 lastMask = ASF_AGE | ASF_GENDER | ASF_FACE3DANGLE;
		res = ASFProcess(handle, Width2, Height2, ASVL_PAF_RGB24_B8G8R8, imageData2, &detectedFaces2, lastMask);
		if (res != MOK)
			printf("ASFProcess fail: %d\n", res);
		else
			printf("ASFProcess sucess: %d\n", res);

		// ��ȡ����
		ASF_AgeInfo ageInfo = { 0 };
		res = ASFGetAge(handle, &ageInfo);
		if (res != MOK)
			printf("%s ASFGetAge fail: %d\n", picPath2, res);
		else
			printf("%s ASFGetAge sucess: %d First face age: %d\n", picPath2, res, ageInfo.ageArray[0]);

		// ��ȡ�Ա�
		ASF_GenderInfo genderInfo = { 0 };
		res = ASFGetGender(handle, &genderInfo);
		if (res != MOK)
			printf("%s ASFGetGender fail: %d\n", picPath2, res);
		else
			printf("%s ASFGetGender sucess: %d First face gender: %d\n", picPath2, res, genderInfo.genderArray[0]);

		// ��ȡ3D�Ƕ�
		ASF_Face3DAngle angleInfo = { 0 };
		res = ASFGetFace3DAngle(handle, &angleInfo);
		if (res != MOK)
			printf("%s ASFGetFace3DAngle fail: %d\n", picPath2, res);
		else
			printf("%s ASFGetFace3DAngle sucess: %d First face 3dAngle: roll: %lf yaw: %lf pitch: %lf\n", picPath2, res, angleInfo.roll[0], angleInfo.yaw[0], angleInfo.pitch[0]);

		SafeFree(copyfeature1.feature);		//�ͷ��ڴ�
		SafeArrayDelete(imageData1);
		SafeArrayDelete(imageData2);
		
		//��ȡ�汾��Ϣ
		const ASF_VERSION* pVersionInfo = ASFGetVersion(handle);

		//��������
		res = ASFUninitEngine(handle);
		if (res != MOK)
			printf("ALUninitEngine fail: %d\n", res);
		else
			printf("ALUninitEngine sucess: %d\n", res);
	}
	else{
		printf("No pictures found.\n");
	}

	getchar();
    return 0;
}

