//
//  ResourceManager.h
//  ClsLib
//
//  Created by wangjl on 15/8/27.
//  Copyright (c) 2015年 wangjl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

#define UserId @""
static NSString *appBundleName = @"tc_default";

NS_INLINE UIImage * UIResourceBundleImage(NSString *strPath){
    return [UIImage imageNamed:[NSString stringWithFormat:@"%@.bundle/image/%@.png",appBundleName,strPath]];
}

NS_INLINE NSDictionary *PropertyList(NSString *strPath){
    NSString *strBundlePath = [[NSBundle mainBundle]pathForResource:appBundleName ofType:@"bundle"];
    NSBundle* myBundle =[NSBundle bundleWithPath:strBundlePath];
    
    // Obtain a reference to a loadable bundle.
    
    NSString *resultPath = [myBundle pathForResource:strPath ofType:nil];
    NSDictionary *dictionary=[[NSDictionary alloc]initWithContentsOfFile:resultPath];
    return dictionary;
}

NS_INLINE NSArray *PropertyArrayList(NSString *strPath){
    NSString *strBundlePath = [[NSBundle mainBundle]pathForResource:appBundleName ofType:@"bundle"];
    NSBundle* myBundle =[NSBundle bundleWithPath:strBundlePath];
    
    // Obtain a reference to a loadable bundle.
    
    NSString *resultPath = [myBundle pathForResource:strPath ofType:nil];
 
    NSArray *arrResult =  [NSArray  arrayWithContentsOfFile:resultPath];
    return arrResult;
}

NS_INLINE NSData *UIResourceBundleFile(NSString *strPath){
    NSString *strBundlePath = [[NSBundle mainBundle]pathForResource:appBundleName ofType:@"bundle"];
    NSBundle* myBundle =[NSBundle bundleWithPath:strBundlePath];
    
    // Obtain a reference to a loadable bundle.
    
    NSString *resultPath = [myBundle pathForResource:strPath ofType:nil];
    NSData *data = [NSData dataWithContentsOfFile:resultPath];
    return data;
}
@interface ResourceManager : NSObject

+(NSString *)appDocumentsDirectory;

+(NSString *)appCachesDirectory;

+(NSString *)applicationSupportDirectory;

+(NSString *)appTemporaryDirectory;

+(NSString *)currentUserDirectory;

+(NSString *)userDirectoryWithID:(NSString *)userID;
+(NSArray *)getFilesInDir:(NSString *)dir;
+(BOOL)resolveDirectoryAtPath:(NSString *)dirPath;
+(BOOL)isExist:(NSString *)filePath;

+(NSString *)filePathWithName:(NSString *)strFileName;
+(BOOL)createPlistFile:(NSString *)strFileName;
+(NSDictionary *)dicFromPlist:(NSString *)strFileName;
+(NSArray *)arrFromPlist:(NSString *)strFileName;

@end
