# Arduion関連
## Pressure_oled
圧力を測定した結果をoledに表示する

## Air_controller_test
電磁弁の性能テスト用
何msから応答するか → pwmの分周で対応可能か確認する

## Air_controller 
3流路の電磁弁操作
単純なON,OFFの操作
使用する電磁弁 : 

## Air_controller_continue
3流路の電磁弁操作
pwmを使用した連続的な圧力操作
使用する電磁弁 :
pwmの周波数 : 
### 動作システム
|Air1|Air2|Air3|
|:--:|:--:|:--:|
|1|0|0|
|0.5|0.5|0|
|0|1|0|
|0|0.5|0.5|
|0|0|1|
|0.5|0|0.5|