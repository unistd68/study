// var movies=[
//     {"no":"01","title":"20年200大进球","type":"mp4","src":"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%2920%E5%B9%B4%C2%B7200%E5%A4%A7%E8%BF%9B%E7%90%83%20%E6%AC%A3%E8%B5%8F%E9%82%A3%E4%BA%9B%E7%BE%8E%E5%A6%99%E8%BF%9B%E7%90%83.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20211127T060857Z&X-Amz-Expires=604799&X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ&X-Amz-SignedHeaders=host&versionId=null&X-Amz-Signature=3c08c1531b59f63711385cd6fddc3b8c4235ab129370b4736725ef5d9b24d61d"},
// 	{"no":"02","title":"20年20大纪录","type":"mp4","src":"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%2920201109%2020%E5%B9%B420%E5%A4%A7%E7%BA%AA%E5%BD%95.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20211127T060840Z&X-Amz-Expires=604799&X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ&X-Amz-SignedHeaders=host&versionId=null&X-Amz-Signature=05b45845b07c0209f1e3799d46d751c8ab9b909592fcf5dd2994141d0442a959"},
//     {"no":"03","title":"那些年，我们一起追的球星：亨利","type":"mp4","src":"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%29%E9%82%A3%E4%BA%9B%E5%B9%B4%EF%BC%8C%E6%88%91%E4%BB%AC%E4%B8%80%E8%B5%B7%E8%BF%BD%E7%9A%84%E7%90%83%E6%98%9F%EF%BC%9A%E4%BA%A8%E5%88%A9.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20211127T060947Z&X-Amz-Expires=604799&X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ&X-Amz-SignedHeaders=host&versionId=null&X-Amz-Signature=1641565209634e961bf8faa89e0885cce6db3f3032dfedeb30c53047a572c251"},
//     {"no":"04","title":"那些年，我们一起追的球星：卡卡","type":"mp4","src":"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%29%E9%82%A3%E4%BA%9B%E5%B9%B4%EF%BC%8C%E6%88%91%E4%BB%AC%E4%B8%80%E8%B5%B7%E8%BF%BD%E7%9A%84%E7%90%83%E6%98%9F%EF%BC%9A%E5%8D%A1%E5%8D%A1.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20211127T061001Z&X-Amz-Expires=604799&X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ&X-Amz-SignedHeaders=host&versionId=null&X-Amz-Signature=7b319ec89a1dffc2642d6edf7d7875dafd45e8e58369fdca11a42b503a554663"},
//     {"no":"05","title":"那些年，我们一起追的球星：克洛泽","type":"mp4","src":"http://192.168.1.113:9000/video/%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83/%28%E5%A4%A9%E4%B8%8B%E8%B6%B3%E7%90%83%29%E9%82%A3%E4%BA%9B%E5%B9%B4%EF%BC%8C%E6%88%91%E4%BB%AC%E4%B8%80%E8%B5%B7%E8%BF%BD%E7%9A%84%E7%90%83%E6%98%9F%EF%BC%9A%E5%85%8B%E6%B4%9B%E6%B3%BD.mp4?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=R6BAM3HAOXM0NGA9S7AD%2F20211127%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20211127T061013Z&X-Amz-Expires=604799&X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJSNkJBTTNIQU9YTTBOR0E5UzdBRCIsImV4cCI6MTYzNzk5NjYyNSwicG9saWN5IjoiY29uc29sZUFkbWluIn0.3T60EyAgkZZ4gBLc4hxCrIg6AEajLSp0H44QOk0IEDF6GwYLSji7A6Y28VwnzDmr_wE-seRfs0FI0FG8XOCKjQ&X-Amz-SignedHeaders=host&versionId=null&X-Amz-Signature=f026589b6b4731248c50114ad472535995d36f3e8e048c027f9c986bcf539720"},
// 	{"no":"05","title":"测试","type":"mp4","src":"http://192.168.1.113:9000/test/%E3%80%904K60FPS%E3%80%91%E9%99%88%E5%A5%95%E8%BF%85%E3%80%8A%E6%B5%AE%E5%A4%B8%E3%80%8B%E6%9C%80%E7%82%B8%E8%A3%82%E7%9A%84%E7%8E%B0%E5%9C%BA%EF%BC%81%E5%97%93%E5%AD%90%E6%B2%99%E5%93%91%E5%85%A8%E7%A8%8B%E6%A0%B8%E8%83%BD.flv?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=Q9RRFYXM70AQ8CURT9RK%2F20211127%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20211127T065737Z&X-Amz-Expires=604799&X-Amz-Security-Token=eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJhY2Nlc3NLZXkiOiJROVJSRllYTTcwQVE4Q1VSVDlSSyIsImV4cCI6MTYzNzk5OTc1NiwicG9saWN5IjoiY29uc29sZUFkbWluIn0.Ybk7NX1FD8ZezLNBNyB3jUqQ9Fj4ayQj6a0q2Eqy7BgKk_Wu9CrFafw0Ih3lb0VByPU4QmMvbhXbPSidETpi9A&X-Amz-SignedHeaders=host&versionId=null&X-Amz-Signature=4d2bb13317f94d7d7a2723cd517dd99139b3adff565dce570bcf0f8d3c2db106"}
// ];
// var lis = [];
var url = [];
var title = [];
// var oMovies=eval(movies);
var aside=document.getElementById("playList");
var oUL=document.getElementById("playListUl");
var goUrl="http://192.168.1.113:8889/video/getVideoMsg"
var urlPrefix="http://192.168.1.113:9000/video/天下足球/"

var HttpClient = function() {
    this.get = function(aUrl, aCallback) {
        var anHttpRequest = new XMLHttpRequest();
        anHttpRequest.onreadystatechange = function() { 
            if (anHttpRequest.readyState == 4 && anHttpRequest.status == 200)
                aCallback(anHttpRequest.responseText);
        }
 
        anHttpRequest.open( "GET", aUrl, true );            
        anHttpRequest.send( null );
    }
}


window.onload = function(){
	var client = new HttpClient();
	client.get(goUrl, function(response) {
		// do something with response
		console.log(response);
		var obj = JSON.parse(response);
		var vLen = obj.data.length;
		console.log(obj.data.length);
		for(var i=0;i<vLen;i++){
			var jsonItem = obj.data[i];
			var item = document.createElement('li');
			item.setAttribute('value',urlPrefix+String(jsonItem["url"])); 
			console.log(urlPrefix+jsonItem["url"]);
			item.setAttribute('title',jsonItem["title"]); 
			item.innerHTML = jsonItem["title"];
			console.log(jsonItem["title"]);
			if(i==0)
			{
				item.className = "select";
			}
			document.getElementById("playListUl").appendChild(item);
			url[i] = urlPrefix+String(jsonItem["url"]);
			title[i] = jsonItem["title"];
			
			// lis.push(item);
		}

		var lis = document.getElementsByTagName("li");
		var video = document.getElementById("video");
		var vLen = lis.length; // 播放列表的长度
		console.log(vLen);
		

		var curr = 0; // 当前播放的视频
		var next = curr + 1;
		
		// for(var i=0;i<lis.length;i++){
		// 	url[i] = lis[j].getAttribute("value");
		// }
		
		//绑定单击事件
		for(var i=0;i<vLen;i++){
				lis[i].onclick = function(){
					for(var j=0;j<vLen;j++){
						if(lis[j] == this){
							// video.setAttribute("src",this.getAttribute("value"));
							video.setAttribute("src",url[j]);
							video.setAttribute('autoplay','autoplay');
							this.innerHTML = '  '+this.innerHTML;
							this.className = "select";
							curr = j;
							next = curr + 1;
						}else{
							lis[j].innerHTML = lis[j].getAttribute("title");
							lis[j].className = "";
						}
					}
			}
		}	
		

		video.setAttribute('src',url[0]);
		lis[0].innerHTML = ' '+title[0];
		lis[0].className = "select";
		
		
		
		video.addEventListener('ended', play);
		//play();
		function play() {
			console.log("curr:"+curr);
			console.log("next:"+next);
			if (curr + 1 >= vLen) next = 0; // 列表末尾，重新播放
			for(var j=0;j<vLen;j++){
				if(j == next){
					video.setAttribute("src",url[j]);
					console.log(lis[j].getAttribute("value"));
					video.setAttribute('autoplay','autoplay');
					lis[j].innerHTML = ' '+ lis[j].innerHTML;
					lis[j].className = "select";
				}else{
					lis[j].innerHTML = lis[j].getAttribute("title");
					lis[j].className = "";
				}
			}
		video.src = url[next];
		video.load(); // 如果短的话，可以加载完成之后再播放，监听 canplaythrough 事件即可
		video.play();
		curr = next;
		next ++;
		}
		console.log("check begin");
		for(var i=0;i<vLen;i++)
		{
			console.log(i+":");
			console.log(lis[i].getAttribute("value"));
			console.log(lis[i].getAttribute("title"));
		}

	});

	
}



