// Objective-C API for talking to github.com/dabankio/wallet-core/core/bbc Go package.
//   gobind -lang=objc github.com/dabankio/wallet-core/core/bbc
//
// File is generated by gobind. Do not edit.

#ifndef __Bbc_H__
#define __Bbc_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Bip44.objc.h"

@class BbcKeyInfo;
@class BbcTemplateInfo;
@class BbcTxBuilder;

/**
 * KeyInfo 私钥，公钥，地址
 */
@interface BbcKeyInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull privateKey;
@property (nonatomic) NSString* _Nonnull publicKey;
@property (nonatomic) NSString* _Nonnull address;
@end

/**
 * TemplateInfo 简要模版信息
 */
@interface BbcTemplateInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Type 类型
 */
@property (nonatomic) long type;
/**
 * Address 地址
 */
@property (nonatomic) NSString* _Nonnull address;
/**
 * RawHex hex编码的原始数据（TemplateData）
 */
@property (nonatomic) NSString* _Nonnull rawHex;
@end

/**
 * TxBuilder transaction builder
 */
@interface BbcTxBuilder : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewTxBuilder new 一个transaction builder
 */
- (nullable instancetype)init;
// skipped field TxBuilder.TXBuilder with unsupported type: *github.com/dabankio/gobbc.TXBuilder

/**
 * AddInput 参考listunspent,确保输入金额满足amount
 */
- (BbcTxBuilder* _Nullable)addInput:(NSString* _Nullable)txid vout:(int8_t)vout;
/**
 * AddTemplateData 添加模版原始数据,多个模版时需要自行确保顺序
 */
- (BbcTxBuilder* _Nullable)addTemplateData:(NSString* _Nullable)tplData;
/**
 * Build 构造交易,返回hex编码的tx
 */
- (NSString* _Nonnull)build:(NSError* _Nullable* _Nullable)error;
/**
 * ExcludeAnchor MKF需要调用该函数(使得序列化时不会处理anchor字段)
 */
- (BbcTxBuilder* _Nullable)excludeAnchor;
/**
 * SetAddress 转账地址,目前只支持公钥地址
 */
- (BbcTxBuilder* _Nullable)setAddress:(NSString* _Nullable)add;
/**
 * SetAmount 转账金额
 */
- (BbcTxBuilder* _Nullable)setAmount:(double)amount;
/**
 * SetAnchor 锚定分支id
 */
- (BbcTxBuilder* _Nullable)setAnchor:(NSString* _Nullable)anchor;
/**
 * SetData 自动编码数据,自动生成uuid和时间戳, dataFmtDesc: 空字符串或格式如 JSON
 */
- (BbcTxBuilder* _Nullable)setData:(NSString* _Nullable)dataFmtDesc data:(NSData* _Nullable)data;
/**
 * SetDataWith 指定uuid,timestamp,data， , dataFmtDesc: 空字符串或格式如 JSON
 */
- (BbcTxBuilder* _Nullable)setDataWith:(NSString* _Nullable)p0 timestamp:(int64_t)timestamp dataFmtDesc:(NSString* _Nullable)dataFmtDesc data:(NSData* _Nullable)data;
/**
 * SetDataWithUUID 该函数已废弃，请使用SetDataWith
 */
- (BbcTxBuilder* _Nullable)setDataWithUUID:(NSString* _Nullable)p0 timestamp:(int64_t)timestamp data:(NSData* _Nullable)data;
- (void)setErr:(NSError* _Nullable)e;
/**
 * SetFee 手续费，目前0.01，如果带data则0.03, 额外需咨询BBC
 */
- (BbcTxBuilder* _Nullable)setFee:(double)fee;
/**
 * SetLockUntil lock until
 */
- (BbcTxBuilder* _Nullable)setLockUntil:(long)lockUntil;
/**
 * SetRawData 原始data设置,需自行编码uuid time等
 */
- (BbcTxBuilder* _Nullable)setRawData:(NSData* _Nullable)data;
/**
 * SetStringData 该函数已废弃，请使用SetData
 */
- (BbcTxBuilder* _Nullable)setStringData:(NSString* _Nullable)data;
/**
 * SetTimestamp 交易时间戳
 */
- (BbcTxBuilder* _Nullable)setTimestamp:(long)timestamp;
/**
 * SetType typ
 */
- (BbcTxBuilder* _Nullable)setType:(long)v;
/**
 * SetVersion 当前版本 1
 */
- (BbcTxBuilder* _Nullable)setVersion:(long)v;
@end

/**
 * .
 */
FOUNDATION_EXPORT NSString* _Nonnull const BbcSymbolBBC;
/**
 * .
 */
FOUNDATION_EXPORT NSString* _Nonnull const BbcSymbolMKF;

@interface Bbc : NSObject
// skipped variable FullnameMap with unsupported type: map[string]string

@end

/**
 * Address2pubk 将地址转换为公钥
 */
FOUNDATION_EXPORT NSString* _Nonnull BbcAddress2pubk(NSString* _Nullable address, NSError* _Nullable* _Nullable error);

/**
 * CalcTxid 计算txid, symbol: BBC|MKF
 */
FOUNDATION_EXPORT NSString* _Nonnull BbcCalcTxid(NSString* _Nullable symbol, NSString* _Nullable rawTx, NSError* _Nullable* _Nullable error);

/**
 * CreateTemplateDataDexOrder 获取dexOrder模版数据
 */
FOUNDATION_EXPORT BbcTemplateInfo* _Nullable BbcCreateTemplateDataDexOrder(NSString* _Nullable sellerAddress, NSString* _Nullable coinpair, int64_t price, int32_t fee, NSString* _Nullable recvAddress, int32_t validHeight, NSString* _Nullable matchAddress, NSString* _Nullable dealAddress, int64_t timestamp, NSError* _Nullable* _Nullable error);

/**
 * DecodeSymbolTX 解析原始交易（使用JSON RPC createtransaction 创建的交易）,symbol: BBC | MKF
 */
FOUNDATION_EXPORT NSString* _Nonnull BbcDecodeSymbolTX(NSString* _Nullable symbol, NSString* _Nullable rawTX, NSError* _Nullable* _Nullable error);

/**
 * NewSymbolBip44Deriver symbol: BBC | MKF 获取bip44推导
 */
FOUNDATION_EXPORT id<Bip44Deriver> _Nullable BbcNewSymbolBip44Deriver(NSString* _Nullable symbol, NSString* _Nullable bip44Path, NSString* _Nullable bip44Key, NSData* _Nullable seed, NSError* _Nullable* _Nullable error);

// skipped function NewSymbolCoin with unsupported parameter or return types


/**
 * NewTxBuilder new 一个transaction builder
 */
FOUNDATION_EXPORT BbcTxBuilder* _Nullable BbcNewTxBuilder(void);

/**
 * ParsePrivateKey 解析私钥，返回 privateKey,publicKey,address
 */
FOUNDATION_EXPORT BbcKeyInfo* _Nullable BbcParsePrivateKey(NSString* _Nullable privateKey, NSError* _Nullable* _Nullable error);

/**
 * Pubk2address 公钥转地址
 */
FOUNDATION_EXPORT NSString* _Nonnull BbcPubk2address(NSString* _Nullable pubk, NSError* _Nullable* _Nullable error);

/**
 * SymbolSignWithPrivateKey 指定币种使用私钥对交易签名
 */
FOUNDATION_EXPORT NSString* _Nonnull BbcSymbolSignWithPrivateKey(NSString* _Nullable symbol, NSString* _Nullable rawTX, NSString* _Nullable templateData, NSString* _Nullable privateKey, NSError* _Nullable* _Nullable error);

#endif
