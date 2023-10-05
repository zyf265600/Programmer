import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'stringchunck'
})
export class StringchunckPipe implements PipeTransform {

  transform(value: unknown, ...args: unknown[]): unknown {
    return null;
  }

}
