<?php
    $requrl = "https://www.qq.com";
    $timeout = 5;

	$ch = curl_init();
    $timeout = 5;
	curl_setopt($ch, CURLOPT_URL, $requrl);
	curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_HEADER, 1);
	curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE); // 对认证证书来源的检查
	curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, FALSE); // 从证书中检查SSL加密算法是否存在

    $fileContents = curl_exec($ch);
    if(false === $fileContents)
    {
    	$errno = curl_errno($ch);
    	$errmsg = curl_error($ch);
		curl_close($ch);
		print("curl_exec fail, errno:$errno, errmsg:$errmsg");
		return false;
    }

    // 获得响应结果里的：头大小
	$headerSize = curl_getinfo($ch, CURLINFO_HEADER_SIZE);
    curl_close($ch);

	// 根据头大小去获取头信息内容
	$header = substr($fileContents, 0, $headerSize);
	$body = substr($fileContents, $headerSize);

    var_dump($header);
    var_dump($body);



?>

