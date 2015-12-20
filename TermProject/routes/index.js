var express = require('express');
var mysql = require('mysql');
var router = express.Router();

var pool = mysql.createPool({
  connectionLimit: 3,
  host: '172.20.10.6',
  user: 'pi',
  database: 'Term_Project',
  password: 'al421s'
});

var location='/';
/* GET home page. */
router.get('/', function(req, res, next) {

  var leds=[];

  pool.getConnection(function (err, connection) {

  connection.query('SELECT Use FROM news_setting',function(err,rows) {
    if (err) throw err;

    for(var i=0; i<rows.length; i++ )
    {
      var led = { use : rows[i].Use};
      leds.push(led);
    }

  });

  console.log("확인 "+leds[0]+" "+leds[1]+" "+leds[2]+" "+leds[3]);
  res.render('index', {led:leds});

  connection.release();
  });
});

router.post('/',function(req,res,next){

  var button =new Array();

  b[0]=(req.body.button1)?1:0;
  b[1]=(req.body.button2)?1:0;
  b[2]=(req.body.button3)?1:0;
  b[3]=(req.body.button4)?1:0;
  var date=req.body.date;
  var minute=req.body.minute;

 console.log("확인 "+b[0]+" "+b[1]+" "+b[2]+" "+b[3]+" "+date+" "+minute);

 pool.getConnection(function (err, connection) {
   for(var i=0; i<4; i++){
     connection.query('UPDATE news_setting set Use= ? where Id=? ' ,[b[i],i],function(err,rows){
      if (err) throw err;
      });

    }

    connection.query('Insert into time_setting(date,minute) values(?,?)',[date,minute],function(err,rows){
     if (err) throw err;
     });

      if(b[0]==1)
       $.get("led1_on.php");
      else
       $.get("led1_off.php");

     if(b[1]==1)
      $.get("led2_on.php");
     else
      $.get("led2_off.php");

      if(b[2]==1)
       $.get("led3_on.php");
      else
       $.get("led3_off.php");

       if(b[3]==1)
        $.get("led4_on.php");
       else
        $.get("led4_off.php");

    //작업완료! (get으로 다시보냄))
    var sendMessage="/";
    res.redirect(sendMessage);

  connection.release();
 });
});


module.exports = router;
