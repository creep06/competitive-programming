function main(input) {
	const num = input.split(' ').map(n => Number(n));
	console.log(num[0]*num[1]%2 ? 'Odd' : 'Even');
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
