var fakeInput = `4
2 120
1 2013-07-01 15:59 2013-07-08 16:30
2 2013-07-08 17:30 2013-07-15 12:00
3 60
65 2013-07-08 14:30 2013-07-08 16:00
32 2013-07-01 16:00 2013-07-15 12:00
91 2013-07-01 16:00 2013-07-08 15:00
2 360
a7 2016-02-21 14:00 2016-02-28 21:00
xx 2016-03-01 01:00 2016-03-02 12:57
2 60
a9 2016-02-21 14:00 2016-02-28 11:00
a8 2016-02-28 12:00 2016-03-11 21:00`.split('\n')

// console.log(fakeInput);

var n = parseInt(readline());
// var n = 1
for (var i = 0; i < n; i++){
	process();
}

function process () {
	var text = readline().split(' ');
	// var text = '2 360'.split(' ');
	var num_bookings = parseInt(text[0]);
	var sec_clean = parseInt(text[1]) * 60;
	var bookings = []

	// fakeInput = ['a7 2016-02-21 14:00 2016-02-28 21:00', 'xx 2016-03-01 01:00 2016-03-02 12:57'];

	for(var i = 0; i < num_bookings; i++){
		var raw_booking = readline().split(' ')
		// var raw_booking = fakeInput[i].split(' ')
		var start_booking = raw_booking.slice(1, 3).join(' ');
		var finish_booking = raw_booking.slice(3).join(' ');
		var booking = {}
		booking.start = new Date(start_booking);
		booking.finish = new Date(finish_booking);
		bookings.push(booking);
	}

	// console.log(bookings);

	// sort
	bookings.sort(function (a, b) {
		return (a.start - b.start === 0) ? (a.finish - b.finish) : (a.start - b.start)
	})

	// end sort

	// console.log(bookings);
	var mark = [];
	for(var j = 0; j < num_bookings; j++){
		mark.push(0);
	}
	mark[0] = 1;

	var can_reduce = 0;

	for(var j = 0; j < num_bookings - 1; j++){
		for (var k = j + 1; k < num_bookings; k++) {
			if ((mark[k] == 0) && (bookings[j].finish <= bookings[k].start)){
				var diff = bookings[k]['start'] - bookings[j]['finish']
				diff = Math.floor(diff / 1000)
				// console.log(diff + " : " + sec_clean);
				// console.log(diff >= sec_clean);
				if (diff >= sec_clean){
					can_reduce++;
					mark[k] = 1;
				}
			}
		}
	}

	print(num_bookings - can_reduce);
	// print('\n');
	// console.log(num_bookings - can_reduce)
}