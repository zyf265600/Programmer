import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'stringchunck'
})
export class StringchunckPipe implements PipeTransform {
  
  transform(value: string, limit?: number, ok: number) {
    if (!value) return null;
    let actualLimit = (limit) ? limit : 50;
    return value.substr(0, actualLimit) + '...';
  }

}
